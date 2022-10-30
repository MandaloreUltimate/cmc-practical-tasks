CXX = ifort -mkl=sequential #gfortran
FLAGS = -O3 -heap-arrays 2048 #-fbounds-check -ffree-line-length-none -lblas -llapack

all: header.o subroutines.o main.o
	$(CXX) $(FLAGS) header.o subroutines.o main.o -o main
	
header.o: header.f90
	$(CXX) $(FLAGS) -c header.f90 -o header.o

subroutines.o: subroutines.f90
	$(CXX) $(FLAGS) -c subroutines.f90 -o subroutines.o

main.o: main.f90
	$(CXX) $(FLAGS) -c main.f90 -o main.o
