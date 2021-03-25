#include <stdio.h>

#define N 1000

int x[N] = {}, y[N] = {};

typedef struct {
	int count;
	int idx;
} Point;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(Point point[], int low, int high) {
	int pivot = point[high].count;
	int i = low - 1;
	for(int j = low; j <= high - 1; j++) {
		if(point[j].count < pivot) {
			i++;
			swap(&point[i].count,&point[j].count);
			swap(&point[i].idx,&point[j].idx);
		} else if(point[j].count == pivot) {
			if(point[j].idx < point[high].idx) {
				i++;
				swap(&point[i].count,&point[j].count);
			    swap(&point[i].idx,&point[j].idx);
			}
		}
	}
	swap(&point[i+1].count,&point[high].count);
	swap(&point[i+1].idx,&point[high].idx);
	return (i+1);
}
void quicksort(Point point[], int low, int high) {
	if(low < high) {
		int pivot = partition(point,low,high);
		quicksort(point,low,pivot-1);
		quicksort(point,pivot+1,high);
	}
	return;
}
int main() {
	int n, c, d, k;
	scanf("%d %d %d %d",&n,&c,&d,&k);

	Point point[n];
	int xc[n], yc[n];
	for(int i = 0; i < n; i++) {
		float a, b;
		scanf("%f %f",&a,&b);

		int A = (int)(a);
		int B = (int)(b);

		xc[i] = A;
		yc[i] = B;

		x[A]++;
		y[B]++;
	}

	for(int i = 0; i < n; i++) {

		point[i].count = x[xc[i]]*y[yc[i]];
		point[i].idx = i;
	}
	quicksort(point, 0, n-1);
	for(int i = 0; i < k; i++) {
		printf("%d ",point[i].idx);
	}
}