#define   EPSILON     0.000001
#define   MAXSTEP     10000

#define   PI          3.141592653


/*-------------------------------------------------------------
 * Jacobian method to compute the eigenvalues and eigenvectors.
 *   A: the input matrix,an n X n mtx,
 *   P: matrix of the eigen vectors,
 *   n: dimension of the matrix.
 * Matrix A will be diagonalized. The eigen values are at the
 * main diagonal.
 * Return the number of iterations.
 */
int jacobian_method(double  **A, double **P,  int n, FILE* fp);

int jacobian_method_without_A(double  **A, double **P, int n, FILE* fp);

int jacobian_method_only_k(double  **A, double **P, int n);

typedef struct {
	double *val;
	int i;
	int j;
}heapElement;

void heapify(heapElement* heap, int n);

void buildHeap(heapElement* heap, double ** A, int n, int * heapSize);

void swapHeap(heapElement * heap, int i, int j);

double popHeap(heapElement * heap, int *p, int *q);


