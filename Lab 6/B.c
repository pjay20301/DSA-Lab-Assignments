#include <stdio.h>
#define min(a,b) ((a>b) ? b : a)
#define max(a,b) ((a<b) ? b : a)
int main() {
	int n;
	scanf("%d",&n);

	int a[n];
	for(int i = 0; i < n; i++) {
		scanf("%d",&a[i]);
	}
    
    int mn[n+1];
    mn[n] = 1000000007;
    mn[n-1] = 1000000007;

	for(int i = n-2; i >= 0; i--) {
		mn[i] = min(mn[i+1],a[i+1]);
	}

	int ans = 0;
	int mx = a[0];
	for(int i = 0; i < n; i++) {
		mx = max(mx,a[i]);
		if(mx <= mn[i])
			ans++;
	}

	printf("%d",ans);
}