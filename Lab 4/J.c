#include<stdio.h>
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
	    return mid;

	  if(a[mid] > x) 
	    return binary_search(a,l,mid-1,x);
	  else if(a[mid] < x)
	  	return binary_search(a,mid+1,r,x);
	}
	
	return -1;
}

int main() {
	int n, q;
	scanf("%d %d",&n,&q);
	int a[n];
	for(int i = 0; i < n; i++) {
		scanf("%d",&a[i]);
	}
	quicksort(a,0,n-1);
	for(int i = 0; i < q; i++) {
		int x;
		scanf("%d",&x);
		int ans = binary_search(a,0,n-1,x);
		if(ans == -1) {
			printf("NO\n");
		} else 
		        printf("YES\n");
	}
}