#include<stdio.h>

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    int p[n], multi[m], cnt = 1;
    for(int i = 0; i < n; i++) {
        scanf("%d",&p[i]);
    }

    for(int i = 0; i < m; i++) {
        scanf("%d",&multi[i]);
    }
    
    for(int i = 0; i < n; i++) {
        if(i < m) {
            cnt *= multi[i];
            p[i] *= cnt;
            printf("%d ",p[i]);
        } else if(i >= m) {
            cnt /= multi[i-m];
            p[i] *= cnt;
            printf("%d ",p[i]);
        }
    }
}