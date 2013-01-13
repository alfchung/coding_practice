
//#define ORIGINAL

#include <iostream>

using namespace std;

void quicksort(int *A, int p, int r);
int qs_partition(int *A, int p, int r);
void swap(int *a, int* b);
void display(int* A, int n);



void quicksort(int *A, int p, int r) {
	
#ifndef ORIGINAL
	if(p==r)
		return;
#endif
	int q = qs_partition(A,p,r);
#ifndef ORIGINAL
	if (q-1>p) //for example, if q==p, no left side to sort
#endif
		quicksort(A,p,q-1);
#ifndef ORIGINAL
	if (q+1<r) //for example, if q==r, no right side to sort
#endif
		quicksort(A,q+1,r);
}

int qs_partition(int *A, int p, int r) {
	cout<<"partion input: ";
	display(A, r-p+1);
	int i = p-1;
	for (int j=p; j<=r-1; ++j ) {
		if ( A[j] <= A[r]) {
			++i;
			swap(&A[j], &A[i]);
		}
	}
	swap(&A[r], &A[i+1]);
	
	cout<<"after partition: ";
	display(A, r-p+1);
	cout<<endl;
	
	return i+1;
}

void swap(int *a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void display(int* A, int n) {
	cout<<"[ ";
	for (int i=0; i<n; i++) {
		cout<<A[i];
		if(i != n-1 )
			cout<<"  ";
		else
			cout<<" ]"<<endl;
	}
}

int main (int argc, char * const argv[]) {
   	
	int A[] = {454,2,6,1,7,36,8,53,86};
	int n = sizeof(A)/sizeof(int);
	cout<<"n="<<n<<endl;
	display(A, n);
	quicksort(A, 0, n-1);
	display(A, n);

    return 0;
}
