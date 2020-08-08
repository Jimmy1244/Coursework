#define _CRT_SECURE_NO_WARNINGS

/***********************************************************
 * This program demonstrate an example of root finding by using
 * Newton's method.
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define EPSILON   0.000001

double   a, b;


/*---------------------------------------------------------------------------
 * The function f(x, y) for the root-finding problem.
 */
double f(double x, double y)
{
    return ((x - 3) * (x - 3) / 25 + (y - 4) * (y - 4) / 16);
}

/*---------------------------------------------------------------------------
 * The function g(x, y) for the root-finding problem.
 */
double g(double x, double y)
{
    return ((x - 3) * (x - 3) / 4 - (y - 4) * (y - 4) / 9);
}

/*-------------------------------------------------
 * Derivatives of f() and g().
 */
double fx(double x, double y)
{
	return (2 * (x - 3) / 25);
}

double fy(double x, double y)
{
	return (2 * (y - 4) / 16);
}

double gx(double x, double y)
{
	return (2 * (x - 3) / 4);
}

double gy(double x, double y)
{
	return (-2 * (y - 4) / 9);
}

//定義解
double nfx(double x, double y)//誤差會更大？
{
	return ((f(x + EPSILON, y) - f(x, y)) / EPSILON);
}

double nfy(double x, double y)//誤差會更大？
{
	return ((f(x, y + EPSILON) - f(x, y)) / EPSILON);
}

double ngx(double x, double y)//誤差會更大？
{
	return ((g(x + EPSILON, y) - g(x, y)) / EPSILON);
}

double ngy(double x, double y)//誤差會更大？
{
	return ((g(x, y + EPSILON) - g(x, y)) / EPSILON);
}

void fixCompute(double delta, double x, double y, double *h, double *k) 
{
	*h = 1 / delta * (gy(x, y) * (1 - f(x, y)) + -fy(x, y) * (1 - g(x, y)));
	*k = 1 / delta * (-gx(x, y) * (1 - f(x, y)) + fx(x, y) * (1 - g(x, y)));
	//printf("\n[delta: %lf]\n[%lf, %lf]\n", delta, *h, *k);////////////////////
	//getchar();////////////////////////////////////////////////////////////////
}

/*--------------------------------------------------------------------------
 * The bisection method.
 *     x, y: the initial value of the root.
 */
double  newton(double *x, double *y, int t, FILE *resultFile)
{
  int     i=1;
  double  err, xnew, ynew, xold, yold;
  double  h, k;
  double  fdx, fdy, gdx, gdy, Delta;
  double  fold, gold;

  
  //Set up initial conditions.
  xold = *x;
  yold = *y;

  fold = f(xold, yold);
  gold = g(xold, yold);
  fdx = fx(xold, yold);///////////////////////////////
  fdy = fy(xold, yold);
  gdx = gx(xold, yold);
  gdy = gy(xold, yold);

  Delta = fabs(fdx*gdy - fdy*gdx);
  //printf("\n[fdx:%lf, gdy: %lf, fdy: %lf, gdx: %lf]\n", fdx, gdy, fdy, gdx);///////////////////////////////////////////////////////////////
  if (Delta == 0) {
	  Delta = EPSILON * 10;//偷懶?
  }
  
  fixCompute(Delta, xold, yold, &h, &k);

  xnew = xold + h;
  ynew = yold + k;
  err = sqrt(fabs(xnew - xold) *  fabs(xnew - xold) + fabs(ynew - yold) * fabs(ynew - yold));

  char filename[20];
  sprintf(filename, "test%2d.txt", t);

  FILE *pfile = fopen(filename, "w");

  fprintf(pfile, "%lf, %lf\n", *x, *y);

  fprintf(stderr, "       i \txn \t\tyn \t\terror\n");
  fprintf(resultFile, "       i \txn \t\tyn \t\terror\n");
  fprintf(stderr,"------------------------------------------------------------\n");
  fprintf(resultFile,"------------------------------------------------------------\n");
  fprintf(stderr, "     %3d \t%lf \t%lf \t------\n", 0, *x, *y);
  fprintf(resultFile, "     %3d \t%lf \t%lf \t------\n", 0, *x, *y);

  while(err >= EPSILON){
   fprintf(stderr,"     %3d \t%lf \t%lf \t%lf\n", i, xnew, ynew, err);
   fprintf(resultFile,"     %3d \t%lf \t%lf \t%lf\n", i, xnew, ynew, err);
   fprintf(pfile, "%lf, %lf\n", xnew, ynew);

   xold = xnew; // Save current value.
   yold = ynew;
   fdx = fx(xold, yold);///////////////////////////////
   fdy = fy(xold, yold);
   gdx = gx(xold, yold);
   gdy = gy(xold, yold);
   Delta = fabs(fdx*gdy - fdy * gdx);
   if (Delta == 0) {
	   Delta = EPSILON * 10;//偷懶?
   }
   fixCompute(Delta, xold, yold, &h, &k);
   xnew = xold + h; // Compute new values.
   ynew = yold + k; // Compute new values.
   err = sqrt(fabs(xnew - xold) *  fabs(xnew - xold) + fabs(ynew - yold) * fabs(ynew - yold)); // Compute the difference.
   i ++;
  }   
  fprintf(stderr,"     %3d \t%lf \t%lf \t%lf\n", i, xnew, ynew, err);
  fprintf(resultFile,"     %3d \t%lf \t%lf \t%lf\n", i, xnew, ynew, err);
  fprintf(pfile, "%lf, %lf\n", xnew, ynew);

  fclose(pfile);

  fprintf(stderr,"------------------------------------------------------------\n"); 
  fprintf(resultFile,"------------------------------------------------------------\n");
  *x = xnew;
  *y = ynew;
  return err;
}


/*----------------------------------------------------------------------------
  * The main procedure.
  */
int main(int argc, char **argv)
{
	srand((unsigned)time(NULL));
	int t, w, i = 0;
	double x, y;
	FILE *resultFile;
	resultFile = fopen("result.txt", "w");
	fprintf(stderr, "How many test cases?  ");
	fscanf(stdin, "%d", &t);
	while (i < t) {
		fprintf(stderr, "How to generate test cases?\n"
			" (1)Input x, y manually \t(2) Random x, y on the ellipse\n"
			" (3) Random x ,y in the ellipse (4) Random x, y beyond the ellipse\n");
		fscanf(stdin, "%d", &w);
		switch (w)
		{
		case 1:
			fprintf(stderr, " Input the initial value x0, y0\n");
			fscanf(stdin, "%lf%lf", &x, &y);
			break;
		case 2://on ellipse
			x = (double)rand() / (double)RAND_MAX * 10 - 2;// -2 ~ 8
			y = sqrt((1.0 - (double)(x - 3) * (x - 3) / 25) * 16) + 4;   //0 ~ 8
			break;
		case 3://in ellipse
			x = (double)rand() / (double)RAND_MAX * 10 - 2;// -2 ~ 8
			y = sqrt((1.0 - (double)(x - 3) * (x - 3) / 25) * 16) + 4;   //0 ~ 8
			double yDis = fabs(4 - y) * 2 * (double)rand() / (double)RAND_MAX;
			y = y < 4 ?  y + yDis : y - yDis;
			break;
		case 4:
			x = (double)rand();
			y = (double)rand();
			if (((x - 3) * (x - 3) / 25 + (y - 4) * (y - 4) / 16) <= 1)
				y += (rand() % 2 ? -9 : 9);//使在橢圓內的點超出橢圓
			break;
		default:
			break;
		}
		double err = newton(&x, &y, i, resultFile);
		fprintf(stderr, "Root= (%lf, %lf, error=%lf)\n\n------------------------------------------------\n\n", x, y, err);
		fprintf(resultFile, "Root= (%lf, %lf, error=%lf)\n\n------------------------------------------------\n\n", x, y, err);
		i++;
	}
	fclose(resultFile);
	getchar();
	getchar();
	return 0;
}