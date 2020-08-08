#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

#include "definition.h"
#include "vec_mtx.h"

//Local global variables for holding temporary values
double   *Bp=NULL, *Bq=NULL;  //The revised p and q columns of A[][].

/*------------------------------------------------------
 * Procedure to print out a matrix.
 */
void print_mtx(double **A, int n, FILE *fp)
{
	int i, j;

    for(i=0;i<n;i++){
		fprintf(fp,"\n");
		for(j=0;j<n;j++)
			fprintf(fp,"%12.8f ", A[i][j]);
	}
	fprintf(fp,"\n--------------------------\n");
}

/*-------------------------------------------------------------------------
 * Procedure to update the P[][] matrix for the Jacobi method.
 *    P[][]: the col. mtx of the eigenvectors,
 *    p, q: the pivot column (row) indices
 *    c, s: cosine and sine values of the rotational angle.
 *    n: shape of the P[][] mtx.
 * Functionality: P = P*R(theta);
 */
void update_P_mtx(double **P, int p, int q, double c, double s, int n)
{
   int  k;

   //Compute the new columns
   for(k=0;k<n;k++){
	   Bp[k] = c*P[k][p] + s*P[k][q];
	   Bq[k] = (-s)*P[k][p] + c*P[k][q];
   }
   //Copy into the P[][] mtx.
   for(k=0;k<n;k++){
	   P[k][p] = Bp[k];
	   P[k][q] = Bq[k];
   }
}//end-of-proc.

/*-------------------------------------------------------------------------
 * Procedure to update the A[][] matrix for the Jacobi method.
 *    A[][]: the col. mtx of the eigenvectors,
 *    p, q: the pivot column (row) indices
 *    c, s: cosine and sine values of the rotational angle.
 *    n: shape of the A[][] mtx.
 * Functionality: A = R^T*A*R;
 */
void update_A_mtx(double **A, int p, int q, double c, double s, int n)
{
   int  k;

   //Compute new values of  the p- and q-col (row)
   for(k=0;k<n;k++){
	   if(k!=p && k!=q) Bp[k] = c*A[k][p] + s*A[k][q];
       if(k!=p && k!=q) Bq[k] = -s*A[k][p] + c*A[k][q];
   }
   //Compute the new A[p][p] & A[q][q].
   Bp[p] = c*c*A[p][p] + 2.0*s*c*A[p][q] + s*s*A[q][q];
   Bq[q] = s*s*A[p][p] - 2.0*s*c*A[p][q] + c*c*A[q][q];
   //Update A[p][q] amd A[q][p]
   Bp[q] = Bq[p] = (c*c-s*s)*A[p][q] + s*c*(A[q][q]-A[p][p]);
   //enter the new col. and rows.
   for(k=0;k<n;k++){
    A[p][k] = A[k][p] = Bp[k];
    A[q][k] = A[k][q] = Bq[k];
  }
 // A[p][q] = A[q][p] = 0.0;
}

double offDiag(double **A, int n) {
	int i, j;
	double sum = 0;
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			sum += fabs(A[i][j]);
		}
	}
	return sum;
}

void heapify(heapElement* heap, int n) {//top_down
	int currentIndex = 0;
	int nextIndex;
	while (currentIndex * 2 + 2 <= n) {
		nextIndex = fabs(*(heap[currentIndex * 2 + 1].val)) > fabs(*(heap[currentIndex * 2 + 2].val)) ? currentIndex * 2 + 1 : currentIndex * 2 + 2;
		if (fabs(*(heap[currentIndex].val)) < fabs(*(heap[nextIndex].val)))
			swapHeap(heap, currentIndex, nextIndex);
		currentIndex = nextIndex;
	}
	nextIndex = currentIndex * 2 + 1;
	if (nextIndex == n && fabs(*(heap[currentIndex].val)) < fabs(*(heap[nextIndex].val)))
		swapHeap(heap, currentIndex, nextIndex);
}

void buildHeap(heapElement* heap, double ** A, int n, int* heapSize) {
	int i, j, count = 0;
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			heap[count].val = &(A[i][j]);
			heap[count].i = i;
			heap[count].j = j;
			int parentIndex = (count - 1) / 2, currentIndex = count;
			while (parentIndex >= 0 && fabs(*(heap[parentIndex].val)) < fabs(*(heap[currentIndex].val))) {
				swapHeap(heap, parentIndex, currentIndex);
				currentIndex = parentIndex;
				parentIndex = (currentIndex - 1) / 2;
			}
			count++;
		}
	}
	*heapSize = count - 1;
}

double popHeap(heapElement * heap, int *p, int *q) {
	*p = (heap[0].i);
	*q = (heap[0].j);
	return *(heap[0].val);
}

void swapHeap(heapElement * heap, int i, int j) {
	int temp;
	double *tempP;
	tempP = heap[i].val;
	heap[i].val = heap[j].val;
	heap[j].val = tempP;
	temp = heap[i].i;
	heap[i].i = heap[j].i;
	heap[j].i = temp;
	temp = heap[i].j;
	heap[i].j = heap[j].j;
	heap[j].j = temp;
}


/*-------------------------------------------------------------
 * Jacobian method to compute the eigenvalues and eigenvectors.
 *   A: the input matrix,an n X n mtx,
 *   P: matrix of the eigen vectors,
 *   n: dimension of the matrix.
 * Matrix A will be diagonalized. The eigen values are at the
 * main diagonal.
 * Return the number of iterations.
 */
int jacobian_method(double  **A, double **P,  int n, FILE *fp)
{
	int          k, p, q;
	double   A_pq, c, s;
	double   theta, a, b;

	// Make P = I.
	make_identity_mtx(P, n);
	// Create the temporary space holding the p & q columns
	Bp = alloc_vec(n);
	Bq = alloc_vec(n);

	heapElement* heap = (heapElement*)malloc(sizeof(heapElement) * n * n / 2);

	int heapSize;
	buildHeap(heap, A, n, &heapSize);
	
	// Find the max off-diagonal entry.
	//A_pq = max_off_diag_entry(A, &p, &q, n);
	A_pq = popHeap(heap, &p, &q);
	k = 0;
	while(fabs(A_pq)>EPSILON && k<MAXSTEP){
		a = 2.0*A_pq;
		b = A[p][p]-A[q][q];
	
		if(b==0.0){
		  if(a>0.0) theta = PI/2.0;
		  else theta = 3.0*PI/2.0;
		}else{
		  theta = atan(a/b);
		}
	
	
		theta = theta/2.0;
		c = cos(theta);
		s = sin(theta);
        //Update the p & q col. & rows of P[][].
        update_P_mtx(P, p, q, c, s, n);
		// A = R'*A*R.
	    update_A_mtx(A, p, q, c, s, n);
 		// Find the max off-diagonal entry for next iteration.
	    //A_pq = max_off_diag_entry(A, &p, &q, n);
		heapify(heap, heapSize);
		A_pq = popHeap(heap, &p, &q);
   		k++;
        //Print matrix A[][] for error checking.
		fprintf(fp, "offDiag[%d] = %lf\n", k, offDiag(A, n));
		fprintf(fp,"k=%d, matrix A[][]=\n", k);
		print_mtx(A, n, fp);
	}
	free(heap);
	return (k);
}

int jacobian_method_without_A(double  **A, double **P, int n, FILE *fp)
{
	int          k, p, q;
	double   A_pq, c, s;
	double   theta, a, b;

	// Make P = I.
	make_identity_mtx(P, n);
	// Create the temporary space holding the p & q columns
	Bp = alloc_vec(n);
	Bq = alloc_vec(n);

	heapElement* heap = (heapElement*)malloc(sizeof(heapElement) * n * n / 2);

	int heapSize;
	buildHeap(heap, A, n, &heapSize);

	// Find the max off-diagonal entry.
	//A_pq = max_off_diag_entry(A, &p, &q, n);
	A_pq = popHeap(heap, &p, &q);
	k = 0;
	while (fabs(A_pq) > EPSILON && k < MAXSTEP) {
		a = 2.0*A_pq;
		b = A[p][p] - A[q][q];

		if (b == 0.0) {
			if (a > 0.0) theta = PI / 2.0;
			else theta = 3.0*PI / 2.0;
		}
		else {
			theta = atan(a / b);
		}


		theta = theta / 2.0;
		c = cos(theta);
		s = sin(theta);
		//Update the p & q col. & rows of P[][].
		update_P_mtx(P, p, q, c, s, n);
		// A = R'*A*R.
		update_A_mtx(A, p, q, c, s, n);
		// Find the max off-diagonal entry for next iteration.
		//A_pq = max_off_diag_entry(A, &p, &q, n);
		heapify(heap, heapSize);
		A_pq = popHeap(heap, &p, &q);
		k++;
		//Print matrix A[][] for error checking.
		fprintf(fp, "offDiag[%d] = %lf\n", k, offDiag(A, n));
		/*
		fprintf(fp, "k=%d, matrix A[][]=\n", k);
		print_mtx(A, n, fp);
		*/
	}
	free(heap);
	return (k);
}


int jacobian_method_only_k(double  **A, double **P, int n)
{
	int          k, p, q;
	double   A_pq, c, s;
	double   theta, a, b;

	// Make P = I.
	make_identity_mtx(P, n);
	// Create the temporary space holding the p & q columns
	Bp = alloc_vec(n);
	Bq = alloc_vec(n);

	heapElement* heap = (heapElement*)malloc(sizeof(heapElement) * n * n / 2);

	int heapSize;
	buildHeap(heap, A, n, &heapSize);

	// Find the max off-diagonal entry.
	//A_pq = max_off_diag_entry(A, &p, &q, n);
	A_pq = popHeap(heap, &p, &q);
	k = 0;
	while (fabs(A_pq) > EPSILON && k < MAXSTEP) {
		a = 2.0*A_pq;
		b = A[p][p] - A[q][q];

		if (b == 0.0) {
			if (a > 0.0) theta = PI / 2.0;
			else theta = 3.0*PI / 2.0;
		}
		else {
			theta = atan(a / b);
		}


		theta = theta / 2.0;
		c = cos(theta);
		s = sin(theta);
		//Update the p & q col. & rows of P[][].
		update_P_mtx(P, p, q, c, s, n);
		// A = R'*A*R.
		update_A_mtx(A, p, q, c, s, n);
		// Find the max off-diagonal entry for next iteration.
		//A_pq = max_off_diag_entry(A, &p, &q, n);
		heapify(heap, heapSize);
		A_pq = popHeap(heap, &p, &q);
		k++;
	}
	free(heap);
	return (k);
}
