#include <stdio.h>

#define ll long long 

ll binary_search(ll l, ll r, ll n) {
	ll cubeRoot;

	while(l <= r) {
		ll mid = (l+r)/2;
		ll cube = mid*mid*mid;

		if(cube == n) {
			return mid;
		} else if(cube > n) {
			r = mid - 1;
		} else if(cube < n) {
			l = mid + 1;
			cubeRoot = mid;
		}
	}
	return cubeRoot;
}
int main() {
	ll n;
	scanf("%lld",&n);

	ll cubeRoot;
	if(n > 0) {
		cubeRoot = binary_search(0,n,n);
	} else {
		cubeRoot = -binary_search(0,-n,-n);
	}
	printf("%lld",cubeRoot);

}