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


int main() {
	int n, k1, k2;
	scanf("%d %d %d",&n,&k1,&k2);
	int x[n], y[n];
	for(int i = 0; i < n; i++) {
		scanf("%d",&x[i]);
	}
	for(int i = 0; i < n; i++) {
		scanf("%d",&y[i]);
		x[i] -= y[i];
	}

	quicksort(x,0,n-1);

	int l = 1, r = 0, ans = 0;
	k2 -= k1;

	while(l < n && x[l] + x[r] <= k2)
		l++;

	ans += (n-l)*(l) + (n-l)*(n-l-1)/2;

	printf("%d",ans);
}