#include<stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int mx = 0,cur = 0;
    for(int i = 0; i < n; i++) {
        scanf("\n");
        char c;
        scanf("%c",&c);
        if(c == 'L') {
            int m;
            scanf("%d",&m);
            cur -= m;
            int a[m];
            for(int i = 0; i < m; i++) {
                scanf("%d",&a[i]);
            } 
        } else if(c == 'E') {
            int m1;
            scanf("%d",&m1);
            cur += m1;
            if(cur > mx) {
                mx = cur;
            }
        }
        
    }
    printf("%d",mx);

    return 0;
}