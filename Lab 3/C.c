#include <stdio.h>
#define max(x,y) (x > y ? x : y)
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
int check(int mid, int a[], int n, int k) {
	int pos = a[0];
	int cnt = 1;

	for(int i = 0; i < n; i++) {
		if(a[i] - pos >= mid) {
			pos = a[i];
			cnt++;

			if(cnt == k)
				return 1;
		}
	}
	return 0;
}
int solve(int a[], int n, int k) {
	int cnt = -1;
	int l = 1, r = a[n-1];

	while(l < r) {
		int mid = (l + r)/2;

		if(check(mid,a,n,k)) {
			cnt = max(cnt,mid);
			l = mid + 1;
		} else 
		   r = mid;

	}

	return cnt;
}
int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	int a[m];
	for(int i = 0; i < m; i++) {
		scanf("%d",&a[i]);
	}

	quicksort(a,0,m-1);
    int ans = solve(a,m,n);
	printf("%d",ans);
}