#include <stdio.h>

typedef struct {
	int x;
	int mod;
} ModArr;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(ModArr modArr[], int low, int high) {
	int pivot = modArr[high].mod;
	int i = low - 1;
	for(int j = low; j <= high - 1; j++) {
		if(modArr[j].mod < pivot) {
			i++;
			swap(&modArr[i].mod,&modArr[j].mod);
			swap(&modArr[i].x,&modArr[j].x);
		} else if(modArr[j].mod == pivot) {
			if(modArr[j].x < modArr[high].x) {
				i++;
				swap(&modArr[i].mod,&modArr[j].mod);
			    swap(&modArr[i].x,&modArr[j].x);
			}
		}
	}
	swap(&modArr[i+1].mod,&modArr[high].mod);
	swap(&modArr[i+1].x,&modArr[high].x);
	return (i+1);
}
void quicksort(ModArr modArr[], int low, int high) {
	if(low < high) {
		int pivot = partition(modArr,low,high);
		quicksort(modArr,low,pivot-1);
		quicksort(modArr,pivot+1,high);
	}
	return;
}

int main() {
	int n, k;
	scanf("%d %d",&n,&k);
	ModArr modArr[n];
	for(int i = 0; i < n; i++) {
		scanf("%d",&modArr[i].x);
		modArr[i].mod = modArr[i].x % k;
	}
	quicksort(modArr, 0, n-1);
	for(int i = 0; i < n; i++) {
		printf("%d ",modArr[i].x);
	}
}