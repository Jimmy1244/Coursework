#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include <math.h>
#include <malloc.h>
#include <string.h>

#define n 4
#define m 100 //插入點

//using namespace std;

/*int n = 3;
double f[]={6.0, 9.0, 2.0, 5.0};
//double x[]={1.0, 2.0, 3.0, 4.0};
double c[4];*/



/******************************************************************
 * Procedure to compute Newton polynomial in forward difference.
 * Input:
 *  x[]: (n+1) parametric values,
 *  f[]: (n+1) function values,
 *  n: last index of samples, (n+1) samples
 * Output:
 *  c[]: coefficients of Newton's polynomial, forward divided difference
 *  
 */
void newton(double x[], double f[], double c[])
{
  int    i, j, k;

  //Order 0 divided differences
  for(j=0;j<=n;j++)
    c[j] = f[j];
  //Order 1 to n divided differences
  for(k=1;k<=n;k++){
    for(i=n;i>=k;i--)
      c[i] = (c[i]-c[i-1])/(x[i]-x[i-k]);
  }
  for(k=0;k<=n;k++)
    fprintf(stderr, "C[%d]=%lf\n",k, c[k]);
}


/*--------------------------------------------------------
 * Procedure to evaluate Newton's polynomial.
 *  c[]: coefficients of Newton polynomial.
 *  x[]: parametric values,
 *  t: interpolation position inside range x[0]~x[n],
 *  n: degree of Newton's polynomial
 */
double Horner(double t, double c[], double x[])
{
  double sum;
  int    i;

  sum = c[n];
  for(i=n-1;i>=0;i--)
    sum = sum*(t-x[i]) + c[i];
  return sum;
}

void generateXwYw(double *xw, double *x, double *yw, double *y, double *w) {
	int i;
	for (i = 0; i <= n; i++) {
		xw[i] = x[i] * w[i];
		yw[i] = y[i] * w[i];
	}
}

void QtInAverage(double *qt, double *t) {
	int i;
	double count = 0, avgDif = (t[n] - t[0]) / m;
	for (i = 0; i < m; i++) {
		count += avgDif;
		qt[i] = count;
	}
}

void QtInChordLength(double *qt, double *t) {

}

void  interpolation(double *qcood, double *coodW, double *c, double *t, double *qt) {
	int i;
	newton(t, coodW, c);
	for (i = 0; i <= m; i++) {
		qcood[i] = Horner(qt[i], c, coodW);
	}
}

void projectXY(double *px, double *py, double *qx, double *qy, double *qw) {
	int i;
	for (i = 0; i < m; i++) {
		px[i] = qx[i] / qw[i];
		py[i] = qy[i] / qw[i];
	}
}

void outputXwYw(double *x, double *y, double *w) {
	printf("\tXw\t\tYw\t\tw\n-------------------------------------------------\n");
	int i;
	for (i = 0; i < n; i++) {
		printf("i = %d\t%lf\t%lf\t%lf\n", i, x[i], y[i], w[i]);
	}
	printf("-------------------------------------------------\n\n");
}

void outputQxQy(double *x, double *y, double *w) {
	printf("\tQx\t\tQy\t\tQw\n-------------------------------------------------\n");
	int i;
	for (i = 0; i < m; i++) {
		printf("i = %d\t%lf\t%lf\t%lf\n", i, x[i], y[i], w[i]);
	}
	printf("-------------------------------------------------\n\n");
}

void outputPxPy(double *x, double *y) {
	printf("\tQx\t\tQy\n--------------------------------------\n");
	int i;
	for (i = 0; i < m; i++) {
		printf("i = %d\t%lf\t%lf\n", i, x[i], y[i]);
	}
	printf("--------------------------------------\n\n");
}

void outputToFile(double *x, double *y, double *px, double *py, FILE *file1, FILE *file2) {
	int i;
	fprintf(file1, "%d\n", n);
	for (i = 0; i < n; i++) {
		fprintf(file1, "%lf, %lf\n", x[i], y[i]);
	}
	fprintf(file2, "%d\n", m);
	for (i = 0; i < m; i++) {
		fprintf(file2, "%lf, %lf\n", px[i], py[i]);
	}
}

void freeXwYwQt(double *xw, double *yw, double *qt) {
	free(xw);
	free(yw);
	free(qt);
}

/*----------------------------------------------------------
 * The main procedure
 */
void main(int argc, char **argv)
{
  double x[] = { -8, 8, 8, -8, -8 };
  double y[] = { 0, 0, 6, 6, 0 };
  double t[] = { 1, 2, 3, 4, 5 };
  char mode = getchar();
  char fileName[20] = "outFile";
  while (mode != 0) {
	  switch (mode) {
	  case '1'://普通 weight 1; t 012345
		  strcat(fileName, "1\0");
		  break;
	  case '2'://普通
		  strcat(fileName, "1\0");
		  break;
	  case '3':
		  strcat(fileName, "1\0");
		  break;
	  case '4':

		  break;
	  default:
		  break;
	  }
	  double *qt = (double *)malloc(sizeof(double) * m);
	  QtInAverage(qt, t);
	  double w[] = { 1, 1, 1, 1, 1 };
	  double c[n + 1];
	  double qx[m], qy[m], qw[m];
	  double px[m], py[m];

	  double *xw, *yw;
	  xw = (double *)malloc(sizeof(double) * (n + 1));
	  yw = (double *)malloc(sizeof(double) * (n + 1));
	  generateXwYw(xw, x, yw, y, w);
	  //Compute interpolation
	  interpolation(qx, xw, c, t, qt);
	  interpolation(qy, yw, c, t, qt);
	  interpolation(qw, w, c, t, qt);

	  //Project to XY plane
	  projectXY(px, py, qx, qy, qw);

	  //Output the results
	  FILE* outfileXY, *outfilePxPy;
	  outfileXY = fopen("outXY.txt", "w");
	  outfilePxPy = fopen("outPxPy.txt", "w");
	  outputXwYw(xw, yw, w);
	  outputQxQy(qx, qy, qw);
	  outputPxPy(px, py);
	  outputToFile(x, y, px, py, outfileXY, outfilePxPy);

	  fclose(outfileXY);
	  fclose(outfilePxPy);

	  freeXwYwQt(xw, yw, qt);
	  mode = getchar();
  }
}
