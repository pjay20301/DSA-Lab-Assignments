#include<stdio.h>

int abs(int n) {
   return n>0 ? n : -n;
}
int main() {
    int n;
    scanf("%d",&n);
    int a[2*n];
    for(int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
        a[i+n] = a[i];
    }
    int ans = 0, mx = -2e9, mn = 2e9;
    if(n&1) {
        for(int i = 0; i < n; i++) {
            int cost = 0, cnt = 0;
            for(int j = i; j < i+n; j++) {
                if(cnt&1) {
                    cnt = 0;
                   cost -= (a[j]*a[j]*a[j]); 
                } else {
                    cnt = 1;
                   cost += (a[j]*a[j]); 
                }
            } if(cost > mx) mx = cost;
              else if(cost < mn) mn = cost;
        } printf("%d",abs(mx-mn));
    } else {
        int evenSquare= 0, evenCube = 0, oddSquare = 0, oddCube = 0;
        for(int i = 0; i < n; i++) {
           if(i&1) {
            oddSquare += (a[i]*a[i]);
            oddCube += (a[i]*a[i]*a[i]);
           } else {
            evenSquare += (a[i]*a[i]);
            evenCube += (a[i]*a[i]*a[i]);
           }
        } printf("%d",abs(evenSquare - oddCube - oddSquare + evenCube));
    }
}