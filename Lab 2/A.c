#include<stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int cnt = 0, ans = 0;

    for(int i = n/2; i >= 2; i--) {
        if(n%i == 0) 
            cnt++, ans += i;
        if(cnt == 2) break;
    }
    if(cnt == 2)
        printf("%d",ans);
    else 
        printf("%d",n);

    return 0;
}
