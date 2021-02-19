#include<stdio.h>

int main() {
    int m,n;
    scanf("%d %d", &m,&n);
    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }
    int ans = 0;
    for(int i = 0; i < (1<<n); i++) {
        int cnt = 0,sum = 0;
        for(int j = 0; j < n; j++) {
            if(i & (1<<j) != 0) {
                if(sum + a[j] <= m) {
                    cnt++;
                    sum += a[j];
                }
            }
        }
        if(cnt > ans) ans = cnt;
    }
    printf("%d", ans); 
}