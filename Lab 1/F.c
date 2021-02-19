#include <stdio.h>
#include <math.h> 
#include <string.h> 
#define N 1000005
#define max(x,y) (x > y ? x : y)
long long primes[N], isPrime[N], mark[N], cnt = 0;


int freq[10] = {};

void segmentedSieve(long long l, long long r) {
    for(int i = 0; i < N; i++) 
        isPrime[i] = 1;
    long long lim = sqrt(r);
    for(long long i = 2; i <= lim; i++) {
        if(!mark[i]) {
            primes[cnt++] = i;
            for(long long j = i*i; j <= lim; j += i) {
                mark[j] = 1;
            }
        }
    }
    
    for(long long i = 0; i < cnt; i++) {
        long long k = primes[i];
        
        for(long long j = max(k*k,(l+k-1)/k*k); j <= r; j += k) {
            isPrime[j-l] = 0;
        }
        if(l == 1) isPrime[0] = 0;
    }
    
    for(long long i = l; i <= r ; i++) {
        long long k = i-l,j = i;
        if(isPrime[k]) {
            while(j>0) {
               freq[j%10]++;
               j /= 10; 
            }
        }
    }

    long long mx = 0;
    long long idx = 0;
    for(long long i = 0; i < 10; i++) {
        if(freq[i] > mx) {
            mx = freq[i];
            idx = i;
        }
    }
    printf("%lld %lld\n",idx,mx);
    return;
}
int main() {
    long long a,b;
    scanf("%lld %lld",&a,&b);
    segmentedSieve(a,b);
}