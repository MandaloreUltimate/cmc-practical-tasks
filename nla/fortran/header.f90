module header
    interface
        subroutine LUfactor(A, n, comp_mode, b, LU, time, prec)
            integer(4) :: n, comp_mode, b
            real(8), dimension(n,n) :: A, LU
            real(8) :: time, prec
        end subroutine
    end interface
end module
