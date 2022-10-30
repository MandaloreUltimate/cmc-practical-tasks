typedef double* Matrix;

Matrix initMatrix(int n);
Matrix generateMatrix(int n, int a, int b, int seed=42);
std::tuple <Matrix, double> LUDecomposition(Matrix A, int n);
void printMatrix(Matrix A, int n);
double precision(Matrix A, Matrix LU, int n);