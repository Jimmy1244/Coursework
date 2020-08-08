/*************************************************************
* In this sample program. the power method and inverse power
* method are used to compute the max and min eigenvalues of
* a matrix.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "definition.h"
#include "vec_mtx.h"

/*--- Declare the coef. matrix, the unkown vec. and the rhs.. ---*/
//double   **A, *x, *b;
//int      n; // dimension of the system.



/*------------------------------------------------------
 * Create a Hilbert linear system.
 *   A: the coef. mtx,
 *   b: the right hand side.
 *   n: dimension of matrix.
 */
void Hilbert_linear_system(double **A, double *b, int n)
{
	int  i, j;

	for(i=0;i<n;i++){
		b[i] = 0.0;
		for(j=0;j<n;j++){
			A[i][j] = 1.0/(i+j+1.0);
			b[i] += A[i][j];
		}
	}
}



/*------------------------------------------------------
 * Create a symmetric linear system.
 *   A: the coef. mtx,
 *   b: the right hand side.
 *   n: dimension of matrix.
 */
void symmetric_linear_system(double **A, double *b, int n)
{
	int  i, j;

	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			A[i][j] = A[j][i] = rand()%10;
		}
	}
	for(i=0;i<n;i++){
		b[i] = 0.0;
		for(j=0;j<n;j++) b[i] += A[i][j];
	}
}

void makeAandPxY(double **A, double *b, int m, int n) {
	int  i, j, k;
	double xi;
	for (i = 0; i < m; i++) {
		xi = 1 + i * 0.2;
		b[i] = 0;
		for (j = 0; j < n; j++) {
			A[i][j] = 1;
			for (k = 0; k < j; k++) {
				A[i][j] *= xi;
			}
			b[i] = b[i] * xi + 1;//Horner's algorithm
			//b[i] += A[i][j];
		}
	}
}

/*
*m: length of c
*norm = 0 is infinite norm
*/
double computeError(double *c, int n, int norm) {
	int i;
	if (norm == 0) {
		double max = 0;
		for (i = 0; i < n; i++) {
			if (max < fabs(c[i]))
				max = fabs(c[i]);
		}
		return max - 1;
	}
	else if (norm == 2) {
		double sum = 0;
		for (i = 0; i < n; i++) {
			sum += (c[i] - 1) * (c[i] - 1);
		}
		return sqrt(sum);
	}
	else return 0;
}


/*----------------------------------------------------
 * The main procedure
 */
int main(int argc, char **argv)
{
	int m = 11, n = 8;

	double **A = alloc_mtx(m, n); //m * n
	double **At = alloc_mtx(n, m);//n * m
	double **B = alloc_mtx(n, n);//n * n
	double *c = alloc_vec(n);// n
	double *b = alloc_vec(m);// m
	double *d = alloc_vec(n);// n
// Print out the initial linear system
	makeAandPxY(A, b, m, n);
	mtx_trans(At, A, m, n);
	mtx_mtx_mult(B, At, A, n, m, n);
	transpose_mtx_vec_mult(d, A, b, m, n);

	//original system
	fprintf(stderr, "A[][]=\n");
	print_mtx(A, m, n);
	fprintf(stderr, "b[]=\n");
	print_vec(b, m);
	// Print out the QR decomposition results.
	QR_solver(A, c, b, m, n);
	fprintf(stderr, " After QR decomposition, A[][]=\n");
	print_mtx(A, m, n);
	fprintf(stderr, "The solution c[]=\n");
	print_vec(c, n);
	fprintf(stderr, "Error in 2-norm : %lf\n", computeError(c, n, 2));
	fprintf(stderr, "Error in infinite-norm : %lf\n", computeError(c, n, 0));

	free(A);
	free(At);
	free(B);
	free(b);
	free(c);
	free(d);
	getchar();
}
