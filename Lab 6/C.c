#include <stdio.h>

#define max(a,b) ((a>b) ? a : b)

int countWatermelons(int n, int t[], int time) {
	int sum = 0;
	for(int i = 0; i < n; i++) {
		sum += (time/t[i]);
	}
	return sum;
}
int shortestTime(int n, int k, int t[], int mn, int mx) {

	if(mn < mx) {
		int mid = (mn+mx)/2;

		int watermelons = countWatermelons(n, t, mid);

		if(k == watermelons)
			return mid;

		if(watermelons < k)
			return shortestTime(n, k, t, mid, mx);

		if(watermelons > k)
			return shortestTime(n, k, t, mn, mid);
	}
}
int main() {
	int n,k;
	scanf("%d %d",&n,&k);

	int t[n], mx = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d",&t[i]);
		mx = max(mx, t[i]);
	}

	int minTime = shortestTime(n, k, t, 0, mx*k);
	printf("%d",minTime);


}