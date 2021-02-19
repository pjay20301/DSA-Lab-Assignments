#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int a[n], cnt = 0, m = 1, c = 1, ans = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
        ans += c*a[i];
        cnt++;
        if(cnt == m) {
            cnt = 0;
            m <<= 1;
            c++;
        } 
    }
    printf("%d",ans);

    return 0;
}