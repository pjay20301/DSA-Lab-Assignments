#include <stdio.h>


void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int a[], int b[], int low, int high) {
	int pivot = a[high];
	int i = low - 1;
	for(int j = low; j <= high - 1; j++) {
		if(a[j] < pivot) {
			i++;
			swap(&a[i],&a[j]);
			swap(&b[i],&b[j]);
		}
	}
	swap(&a[i+1],&a[high]);
	swap(&b[i+1],&b[high]);
	return (i+1);
}
void quicksort(int a[], int b[], int low, int high) {
	if(low < high) {
		int pivot = partition(a,b,low,high);
		quicksort(a,b,low,pivot-1);
		quicksort(a,b,pivot+1,high);
	}
	return;
}

int binary_search(int a[], int l, int r, int x, int pref[]) {
	if(r >= l) {
	  int mid = l + (r-l)/2;
	  
	  if(a[mid] == x) 
	    return pref[mid];

	  if(a[mid] > x) 
	    return binary_search(a,l,mid-1,x,pref);
	  else if(a[mid] < x)
	  	return binary_search(a,mid+1,r,x,pref);
	}
	
	return pref[r];


}
int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n],b[m],g[m];
	for(int i = 0; i < n; i++) {
		scanf("%d",&a[i]);
	}

	for(int i = 0; i < m; i++) {
		scanf("%d %d",&b[i],&g[i]);
	}

	quicksort(b,g,0,m-1);
	int pref[m];
	pref[0] = g[0];
	for(int i = 1; i < m; i++) {
       pref[i] = pref[i-1] + g[i];
	}

	for(int i = 0; i < n; i++) {
		int loot = binary_search(b,0,m-1,a[i],pref);
		printf("%d ",loot);
	}

}