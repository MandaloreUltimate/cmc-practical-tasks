program lufortran
    use header
    integer(4) :: n, comp_mode, b
    character(8) :: manual_mode
    real(8) :: time, prec
    real(8), allocatable, dimension(:,:) :: A, LU

    print '(a)', "Enter square matrix (n x n) dimension:"
    print '(a,$)', "n = "
    read *, n
    allocate(A(n,n))
    allocate(LU(n,n))
    LU = 0
    b = 0

    do
        print '(a)', "Manual input of matrix? (Y/N)"
        read *, manual_mode

        if (manual_mode == 'Y') then
            print "(a, i5, a)", "Enter square ", n, "-dimensional matrix:"
            read *, A
            A = transpose(A)
            exit
        else if (manual_mode == 'N') then
            call random_number(A)
            A = floor(20 * A)
            A = A + 1
            exit
        else
            print '(a)', "Answer not recognized, try again."
        end if
    end do

    do
        print '(a)', "How do you want to compute the result?"
        print '(a)', "Type 0 to use default Fortran functions."
        print '(a)', "Type 1 to use BLAS library functions."
        print '(a)', "Type 2 to use LAPACK library functions."
        print '(a)', "Type 3 to use block-matrix computation."
        read *, comp_mode

        if ((comp_mode == 0) .or. (comp_mode == 1) .or. (comp_mode == 2) .or. (comp_mode == 3)) then
            if (comp_mode == 3) then
                print '(a)', "Type block size (n%b == 0)."
                read *, b
            end if
            exit
        end if
    end do

    call LUfactor(A, n, comp_mode, b, LU, time, prec)

    if (manual_mode == 'Y') then
        print "(6f10.3)", transpose(LU)
    end if

    print '("Time = ", f10.2," ms")', 1000 * time
    print '("Precision = ", E10.4)', prec

    deallocate(A)
    deallocate(LU)
end program
