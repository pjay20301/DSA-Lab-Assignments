#include<stdio.h>
int adj[505][505]={};
int vis[505]={};
char colour[505]={};
int cnt[505]={};
int dfs(int i, int n, char color) {
    if(vis[i] == 1) return;
    vis[i] = 1;
    if(color == 'R') colour[i] = 'B',color = 'B';
    else colour[i] = 'R',color = 'R';
    for(int j = 0; j < n; j++) {
        if(adj[i][j] == 1) cnt[i]++,dfs(j,n,color);
    }
}
int main() {
    int n,m;
    scanf("%d %d",&n,&m);

    for(int i = 0; i < m; i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    char color = 'B';
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i,n,color);
        }
    }
    for(int i = 0; i < 505; i++) {
        if(cnt[i] & 1) {
            printf("NEED MORE COLOURS");
            return 0;
        }
    }
    for(int i = 0; i < n; i++) {
        printf("%c",colour[i]);
    }
}