#define _CRT_SECURE_NO_WARNINGS

/****************************************************************************
 * This sample program reveals the accuracy of Gaussian quadrature integration method.
 * The method: different numbers of intervals X different numbers of Gaussian points
 */
#include <stdio.h>
#include <math.h>

//max number of interval
#define   N  16384

//max number of Gaussian points
#define  K   4

//Sample points in [-1, 1], 1-, 2-, 3-, and 4-points. Ignore extra points (the 0s).
double  p[K][K]={{0.0, 0.0, 0.0, 0.0}, {0.5773502691896257, -0.5773502691896257, 0.0, 0.0}, 
                           {0.0, 0.7745966692414834, -0.7745966692414834, 0.0}, 
                           {0.3399810435848563, -0.3399810435848563, 0.8611363115940526, -0.8611363115940526}};
//function values in N interval
//double  f[N][K];
//weights, for 1-, 2-, 3-, and 4-points. Extra weights = 0s.
double  wgt[K][K]={{2.0, 0.0, 0.0, 0.0}, {1.0, 1.0, 0.0, 0.0}, 
                                 {0.888888888888888888888, 0.555555555555555556, 0.555555555555555556, 0.0},
                                 {0.6521451548625461, 0.6521451548625461, 0.3478548451374538, 0.3478548451374538}};
//integral range = [0, 1].
double  a=0.0, b=4.0;


/*-----------------------------------------------------------------------------------------------------
 * Conformation mapping from [-1, 1] to [a, b]
 *  Input:
 *     t: Gaussian point in [-1, 1].
 *     a, b: the 2 ends of the interval.
 *  Return: 
 *     Gaussian point in [a, b].
 *  Called before evaluating function values.
 */
double  conform_map(double t, double a, double b)
{
   double   x;

   x = (b-a)*t/2.0 + (a+b)/2.0;
   return (x);
}

double f(double x, double y) {
	return (sin(x * x * y + y * y * x) + 1);
}


/*---------------------------------------------------------------------------------------------------------
 * Gaussian quadrature integration subroutine.
 * Input:
 *   k: number of Gaussian points used,
 *   a, b: 2 ends of the interval,
 *   f(): the funtion.
 * Return:
 *   The integral value.
 */
double  gauss_quadrature(int k, double xa, double xb, double ya, double yb, double f(double, double))
{
    int   i, j;
    double   sum=0.0;
    double   x, y, t;

    //Acumulate the contribution of all Gaussian points.
    for(i=0;i<k;i++){
        t = p[k-1][i]; //Retrieve the cononical Gauss point
        x = conform_map(t, xa, xb); //Conformation mapping
		for (j = 0; j < k; j++) {
			t = p[k - 1][j];
			y = conform_map(t, ya, yb);
			sum += wgt[k - 1][j] * wgt[k - 1][i]  *  f(x, y); //The integration
		}
    }
     sum = sum * (xb - xa) / 2.0 * (yb - ya) / 2.0; //Scale the integration value.
    return (sum);
}

/*----------------------------------------------------------------------------------------------------------
 * The main procedure 
 */
int main()
{
  char      filename[]="gauss.txt";
  int        k, numInterval, i, j;
  double  gaussSum, localSum;
  double   exactSum, h;
  FILE     *fp;


  //Open the output file
  fp = fopen(filename, "w");
  //Compute the exact sum.
  exactSum = 17.571626810537573;//compute by julia lang with error being smaller than 2.6182678405418294e-7
  fprintf(fp,"Exact integration = %15.14lf\n", exactSum);
  fprintf(fp,"-----------------------------------------------------------------------------\n");
  //Using different number of Gaussian points
  for(k=1;k<=4;k++){
	  fprintf(fp, "No. of Gaussian points = %d\n", k);
  //Using different numbers of intervals
      for(numInterval=1; numInterval<=N; numInterval*=4){
	      fprintf(fp, "  No. of interval = %d\n", numInterval);
          h = (b-a)/numInterval;
	     gaussSum = 0.0;
		  //Integrate function in each interval
	      for(i=0; i<numInterval;i++){
			  for (j = 0; j < numInterval; j++) {
				  localSum = gauss_quadrature(k, a + i * h, a + (i + 1)*h, a + j * h, a + (j + 1)*h, f);
				  gaussSum += localSum;
			  }
		  }
          fprintf(fp,"\tIntegral= \t%15.14lf\n",gaussSum);
	  fprintf(fp, "\tAbsolute error= \t%15.14lf\n\n", fabs(exactSum - gaussSum));//difference from exact #
	  fprintf(fp, "\tRelative Error=    %15.14lf\n\n", fabs(exactSum - gaussSum)/exactSum);
	  }//end for(numInterval)
  }//end for(k)
  fclose(fp);
  return 0;
}//end of main()
  
