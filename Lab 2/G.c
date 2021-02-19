#include <stdio.h> 

int main() {
    int n,m;
    scanf("%d",&n);
    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }
    
    scanf("%d",&m);

    for(int i = 0; i < n; i++) { 
        for(int j = 0; j < n-i-1; j++) {
            if(a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    
    int l = 0, r = n-1, ans = 0;
    while(l < r) {
        if(a[r] + a[l] > m) 
            ans++, r--;
        else if(a[r] + a[l] <= m)
            ans++, r--, l++;
    }
    if(l == r)
        ans++;
    printf("%d",ans);

    return 0;
}