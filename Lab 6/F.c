#include <stdio.h>

int main() {
	int n, t;
	scanf("%d %d",&n,&t);

	int a[n];
	for(int i = 0; i < n; i++) {
		scanf("%d",&a[i]);
	}

	int x, l = 0, r = n-1;

	for(int i = 0; i < t; i++) {
		scanf("%d",&x);

		l = (l+x)%n;
		r = (r+x)%n;

		printf("%d %d\n",a[l],a[r]);
	}
}