#include <stdio.h>
#include <math.h>

int fun(int n, int k) {
    if(n == 0)
        return 1;
    if(k == 0)
        return 1;
    if(n >= (1<<k)) {
        int c = 1<<k;
        return fun(n - c, k) + fun(n, k - 1);
    } else 
       return fun(n, k - 1);
}
int main() {
    int n;
    scanf("%d",&n);
    int k = log2(n);
    int ans = fun(n,k);
    printf("%d",ans);
}