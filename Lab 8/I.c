#include <stdio.h>

int binary_search(int a[], int l, int r, int x) {
	if(l <= r) {
		int mid = l+ (r-l)/2;

		  if(a[mid] == x) 
		    return 1;

		  if(a[mid] > x) 
		    return binary_search(a, l, mid-1, x);
		  else if(a[mid] < x)
		  	return binary_search(a, mid+1, r, x);
	}
	return -1;

}
int main() {
	int n;
	scanf("%d",&n);

	int a[n], k;
	for(int i = 0; i < n; i++) {
		scanf("%d",&a[i]);
	}
	int j = 0;
	while(j < n-1 && a[j] <= a[j+1])
		j++;

	k = j+1;

	int q, x, y;
	scanf("%d",&q);

	for(int i = 0; i < q; i++) {
		scanf("%d",&x);
		
		if(x >= a[k] && x <= a[n-1])
			y = binary_search(a, k, n-1, x);
		else 
			y = binary_search(a, 0, k-1, x);
		
		if(y == 1)
			printf("YES\n");
		else if(y == -1)
			printf("NO\n");
	}

	return 0;
}