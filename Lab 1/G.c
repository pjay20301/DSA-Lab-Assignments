#include<stdio.h>

int adj[505][505] = {};
int vis[505] = {};
int freq[505] = {};

void dfs(int i, int n, int cnt) {
    if(vis[i] != 0) return;
    vis[i] = cnt;
    freq[cnt]++;
    for(int j = 0; j < n; j++) {
        if(adj[i][j] == 1) dfs(j,n,cnt);
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
    int ans = 0, cnt = 1;
    for(int i = 0; i < n; i++) {
        if(vis[i] == 0) {
            ans++;
            dfs(i,n,cnt);
            cnt++;
        }
    }
    printf("\n%d\n",ans);
    for(int i = 0; i < 505; i++) {
        if(freq[i] != 0) printf("%d ",freq[i]);
    }


}