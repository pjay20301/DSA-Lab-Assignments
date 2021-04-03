#include <stdio.h>
#define ll unsigned long long int
ll hash(ll x) {

	x = x%65535;
	x *= (x + 13);
	x = x%(65535);
	return x;
}
int main() {

	ll n;
	scanf("%lld",&n);

	ll a[n];
	for(ll i = 0; i < n; i++) {
		scanf("%lld",&a[i]);
	}


	ll size = n;

	while(size > 1) {

		if(size&1) { 

			ll l = 0;
			for(ll i = 0; i < size-1; i+=2) {
				a[l++] = hash(a[i]*a[i+1]);
			} a[l] = hash(a[size-1]);
			size = (size+1)/2;

		} else {

			ll l = 0;
			for(ll i = 0; i < size; i+=2) {
				a[l++] = hash(a[i]*a[i+1]);
			}
			size = size/2;
		}
		for(ll i = 0; i < size; i++)
			printf("%lld ",a[i]);
		printf("\n");
		
	} 
	ll ans = a[0];
	printf("%lld",ans);
}