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
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int a[n], b[m];
	for(int i = 0; i < n; i++) {
		scanf("%d",&a[i]);
	}
	for(int i = 0; i < m; i++) {
		scanf("%d",&b[i]);
	}

	quicksort(a,0,n-1);
	quicksort(b,0,m-1);


    int l = m-1, ans = 0;
	for(int i = n-1; i >= 0; i--) {
		if(l < 0) break;
       if(b[l] >= a[i]-k && b[l] <= a[i]+k) {
       	ans++;
       	l--;
       } else if(b[l] > a[i]+k) {
       	l--;
       	i++;
       }
	}
	printf("%d",ans);
}


