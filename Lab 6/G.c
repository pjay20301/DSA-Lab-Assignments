#include <stdio.h>

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

int find_descendant(int tree[], int i, int n) {
	if(2*i + 1 >= n)
		return 
}
int main() {
	int n, a, b;
	scanf("%d %d %d",&n,&a,&b);

	int tree[n];
	for(int i = 0; i < n; i++) {
		scanf("%d",&tree[i]);
	}

	int a1, b1, a2, b2;
	a1 = binary_search(tree,0,n,a);
	b1 = binary_search(tree,0,n,b);

	a2 = find_descendant(tree, a1, n);
	b2 = find_descendant(tree, b1, n);
}