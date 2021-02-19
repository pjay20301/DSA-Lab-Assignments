#include <stdio.h>

int main() {
    int n,m;
    scanf("%d",&n);
    m = n*(n-1)/2 - 1;
    int win[2000] = {}, lose[2000] = {};
    for(int i = 0; i < m ;i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        win[u]++;
        lose[v]++;
    }
    int x = 0, y = 0;
    for(int i = 1; i <=  n; i++) {
        if(win[i] + lose[i] != n-1 && x == 0)
            x = i;
        else if(win[i] + lose[i] != n-1)
            y = i;
    }
    if(win[x] >= win[y]) 
        printf("%d %d",x,y);
    else if(win[x] < win[y])
        printf("%d %d",y,x);

}