#include <stdio.h>


void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int a[], int low, int high) {
	int pivot = a[high];
	int i = low - 1;
	for(int j = low; j <= high - 1; j++) {
		if(a[j] < pivot) {
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[high]);
	return (i+1);
}
void quicksort(int a[], int low, int high) {
	if(low < high) {
		int pivot = partition(a,low,high);
		quicksort(a,low,pivot-1);
		quicksort(a,pivot+1,high);
	}
	return;
}

int binary_search(int a[], int l, int r, int x) {
	if(r >= l) {
	  int mid = l + (r-l)/2;
	  
	  if(a[mid] == x) 
	    return mid+1;

	  if(a[mid] > x) 
	    return binary_search(a,l,mid-1,x);
	  else if(a[mid] < x)
	  	return binary_search(a,mid+1,r,x);
	}

	return r+1;
}
int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n],b[m];
	for(int i = 0; i < n; i++) {
		scanf("%d",&a[i]);
	}

	for(int i = 0; i < m; i++) {
		scanf("%d",&b[i]);
	}

	quicksort(a,0,n-1);
    for(int i = 0; i < n; i++) {
    	printf("%d ",a[i]);
    }
    printf("\n");
	for(int i = 0; i < m; i++) {
		if(b[i] < a[0]) {
			printf("0 ");
			continue;
		} else if(b[i] > a[n-1]) {
			printf("%d ",n);
			continue;
		}
		int ans = binary_search(a,0,n-1,b[i]);
		printf("%d ",ans);
	}

}