#include <stdio.h>

int main() {
	int n, k, x;
	scanf("%d %d %d",&n,&k,&x);

	int s[n], t[k];

	for(int i = 0; i < n; i++) {
		scanf("%d",&s[i]);
	}
	int left_students = 0, ans = 0, mxidx = 0;
	for(int i = 0; i < k; i++) {
		scanf("%d",&t[i]);
		int mx = 0;
		left_students += s[t[i]];
		for(int j = t[i]; j < t[i]+x; j++) {
			mx += s[j];
		}

		if(mx > ans) {
			ans = mx;
			mxidx = t[i];
		}
	}

	printf("%d %d", ans, n-left_students+s[mxidx]);

}