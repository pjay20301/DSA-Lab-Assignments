#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);

    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }
    int k = 1, cnt = 0, L = 0, R = 0, r = 0, check = 0;
    for(int i = 0; i < n; i++) {
        if(cnt != k) {
            if(check == 0 && a[i] != -1) {
                L += a[i];
                r = a[i];
                check = 1;
            } else {
                if(a[i] != -1)
                    r = a[i];
            }
        } cnt++;
        if(cnt == k) {
            cnt = 0;
            k *= 2;
            if(a[i] != -1)
                r = a[i];
            R += r;
            r = 0;
            check = 0;
        }
    }
    if(cnt > 0)
        R += r;
    int ans;
    if(L > R)
        ans = L-R;
    else 
        ans = R-L;
    printf("%d",ans);
}