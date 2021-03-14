#include <stdio.h>
int l = 0, r = 0;
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void maxHeapify(int left[], int i) {
	int parent = (i-1)/2;
	if(i >= 0 && left[parent] < left[i]) {
		swap(&left[parent], &left[i]);
		maxHeapify(left, parent);
	}

}

void minHeapify(int right[], int i) {
	int parent = (i-1)/2;
	if(i >= 0 && right[parent] > right[i]) {
		swap(&right[parent], &right[i]);
		minHeapify(right, parent);
	}
}
int findMedian(int x, int left[], int right[]) {
	if(l == r) {
		left[l] = x;
		l++;
		maxHeapify(left, l-1);
	} else if(l > r) {
		right[r] = x;
		r++;
		minHeapify(right, r-1);
	}

	if(l == r) {
		return (left[0]+right[0])/2; 
	} else {
		return left[0];
	}
}
int main() {
	int n;
	scanf("%d",&n);

	int a[n], left[(n+1)/2], right[(n+1)/2];
	for(int i = 0; i < n; i++) {
		scanf("%d",&a[i]);
		printf("%d ",findMedian(a[i], left, right));
	}


}