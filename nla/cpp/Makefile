CXX = icpc
CXXFLAGS = -Wall -O2
OBJ = main.o matrix_ops.o

all: ${OBJ}
	${CXX} ${CXXFLAGS} -o main ${OBJ}

main.o: main.cpp matrix_ops.h
	${CXX} ${CXXFLAGS} -c main.cpp

matrix_ops.o: matrix_ops.cpp matrix_ops.h
	${CXX} ${CXXFLAGS} -c matrix_ops.cpp