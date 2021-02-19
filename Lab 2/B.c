#include<stdio.h>

int adj[1005][1005] = {};
int vis[1005];
void dfs(int i,int n, int vis[]) {
    if(vis[i] == 1) 
       return;
    vis[i] = 1;
    for(int j = 1; j <= n; j++) {
        if(adj[i][j] == 1 && vis[j] == 0) 
            dfs(j,n,vis);
    }
    return;
}
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0; i < m; i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u][v] = 1;
    }
    int ans = 0, cnt = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            if(vis[j]) 
                cnt++, vis[j] = 0;
            else vis[j] = 0;
        if(cnt > ans) 
           ans = cnt;    
        dfs(i,n,vis);
        cnt = 0;
    }
        

       printf("%d",ans);
}