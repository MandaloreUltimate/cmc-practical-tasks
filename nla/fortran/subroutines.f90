subroutine LUfactor(A, n, comp_mode, b, LU, time, prec)
    integer(4) :: n, comp_mode, b, i, info, m
    real(8), dimension(n,n) :: A, LU
    integer(4), allocatable, dimension(:) :: ipiv
    real(8), allocatable, dimension(:) :: work
    real(8), allocatable, dimension(:) :: LU_res
    real(8), allocatable, dimension(:,:) :: L, U, I_mat, L_INV, U_INV, LU_CORNER, LU_res_mat
    real(8) :: time, prec, start, finish
    double precision zero, one
    parameter (zero = 0.0D0, one = 1.0D0)

    LU = 0
    
    !LU factorization
    call cpu_time(start)
    if (comp_mode == 1) then !Fortran default
        do i = 1, n
            LU(i,i:n) = A(i,i:n) - matmul(LU(i,:), LU(:,i:n))
            if (i < n) then
                LU(i+1:n,i) = (A(i+1:n,i) - matmul(LU(i+1:n,:), LU(:,i))) / LU(i,i)
            end if
        end do
    else if (comp_mode == 0) then !BLAS
        allocate(LU_res(n))
        LU_res = 0
        do i = 1, n
            LU_res(:n-i+1) = A(i,i:n)
            call dgemv('T', n, n-i+1, -one, LU(:,i:n), n, LU(i,:), 1, one, LU_res(:n-i+1), 1)
            LU(i,i:n) = LU_res(:n-i+1)

            if (i < n) then
                LU_res(:n-i) = A(i+1:n,i)
                call dgemv('N', n-i, n, -one, LU(i+1:n,:), n-i, LU(:,i), 1, one, LU_res(:n-i), 1)
                LU(i+1:n,i) = LU_res(:n-i) / LU(i,i)
            end if
        end do
        deallocate(LU_res)
    else if (comp_mode == 2) then !LAPACK
        LU = A
        allocate(ipiv(n))
        call dgetrf(n, n, LU, n, ipiv, info)
    else if (comp_mode == 3) then !Block
        LU = A
        allocate(L_INV(b,b))
        allocate(U_INV(b,b))
        allocate(LU_CORNER(b,b))  
        
        m = n / b

        do k = 0, m - 1
            LU_CORNER = 0
            L_INV = 0
            U_INV = 0
            !Factorize A[k][k] block, which might be singular => A is singular or needs permutations
            do i = 1, b
                LU_CORNER(i,i:) = LU(k*b+ i,k*b+ i:(k+1)*b) - matmul(LU_CORNER(i,:), LU_CORNER(:,i:))
                if (i < b) then
                    LU_CORNER(i+1:,i) = (LU(k*b+ i+1:(k+1)*b,k*b+ i) - matmul(LU_CORNER(i+1:,:), LU_CORNER(:,i))) / LU_CORNER(i,i)
                end if
            end do
            LU(k*b+1:(k+1)*b, k*b+1:(k+1)*b) = LU_CORNER
            do i = 1, b
                L_INV(i,1:i-1) = LU_CORNER(i,1:i-1)
                L_INV(i,i) = 1
                U_INV(i,i:b) = LU_CORNER(i,i:b)
            end do

            if (k < m - 1) then
                !A[k][k:n] = L[k][k]^{-1} * A[k][k:n]
                call dtrsm('L', 'L', 'N', 'U', b, n - (k + 1)*b, one, L_INV, b, LU(k*b+1:(k+1)*b, (k+1)*b+1:), b)
                !A[k:n][k] = A[k:n][k] * U[k][k]^{-1} 
                call dtrsm('R', 'U', 'N', 'N', n - (k + 1)*b, b, one, U_INV, b, LU((k+1)*b+1:, k*b+1:(k+1)*b), n - (k+1)*b)
                !A[k+1:n][k+1:n] = A[k+1:n][k] * A[k][k+1:n]
                !LU((k+1)*b+1:, (k+1)*b+1:) = LU((k+1)*b+1:, (k+1)*b+1:) - matmul(LU((k+1)*b+1:, k*b+1:(k+1)*b), LU(k*b+1:(k+1)*b, (k+1)*b+1:))
                call dgemm('N', 'N', n-(k+1)*b, n-(k+1)*b, b, -one, LU((k+1)*b+1:, k*b+1:(k+1)*b), n-(k+1)*b, LU(k*b+1:(k+1)*b, (k+1)*b+1:), b, one, LU((k+1)*b+1:, (k+1)*b+1:), n-(k+1)*b)
            end if 
        end do
        deallocate(L_INV)
        deallocate(U_INV)
        deallocate(LU_CORNER)  
    end if
    call cpu_time(finish)
    time = finish - start

    !Split into L and U matrices
    allocate(L(n,n))
    allocate(U(n,n))
    L = 0
    U = 0
    do i = 1, n
        L(i,1:i-1) = LU(i,1:i-1)
        L(i,i) = 1
        U(i,i:n) = LU(i,i:n)
    end do

    if (comp_mode == 2) then !LAPACK prec: ||A*A^(-1) - I||
        allocate(work(n*n))
        allocate(I_mat(n,n))
        do i = 1, n
            I_MAT(i,i) = 1
        end do
        call dgetri(n, LU, n, ipiv, work, n, info)
        prec = norm2(matmul(A, LU) - I_mat)
        deallocate(ipiv)
        deallocate(work)
        deallocate(I_mat)
    else !Default/BLAS prec: ||LU - A||
        prec = norm2(matmul(L, U) - A)
    end if
end subroutine
