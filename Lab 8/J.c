#include <stdio.h>
#define max(a,b) ((a>b) ? a : b)
int main() {
	int n;
	scanf("%d",&n);

	int dp[n+1], a[n+1], mx = 0;
	dp[0] = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d",&a[i]);
		dp[i] = max(dp[i-1]+a[i], a[i]);
		mx = max(mx, dp[i]);
	}

	printf("%d",mx);

	return 0;
}