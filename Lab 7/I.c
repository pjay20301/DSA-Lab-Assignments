#include <stdio.h>
#define max(a,b) ((a>b) ? a : b)
int dp[100000] = {};
int main() {

	int n, l;
	scanf("%d %d",&n,&l);

	int a[n+1], s[n+1], dp[n+1];
	for(int i = 1; i <= n; i++) {
		scanf("%d",&a[i]);
	}
	dp[0] = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d",&s[i]);
		int cost = 0, j = i;
		while(j >= 1 && a[i]-a[j] <= l) {
			j--;
		}
		dp[i] = max(dp[j]+s[i], dp[i-1]);
	}
	printf("%d",dp[n]);


}