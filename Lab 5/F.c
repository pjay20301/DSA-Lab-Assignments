#include <stdio.h>
int n;
void dfs(int adj[n][n], int vis[], int i) {
	if(vis[i] == 1)
		return;
	vis[i] = 1;
	printf("%d ",i);
	for(int j = 1; j <= n; j++) {
		if(adj[i][j] == 1) 
			dfs(adj,vis,j);
	}
}
int main() {
	int m;
	scanf("%d %d",&n,&m);
        int adj[n][n];
        int vis[n];
	for(int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d",&u,&v);
		adj[u][v] = 1;
		adj[v][u] = 1;
	}

	for(int i = 1; i <= n; i++) {
		if(vis[i] != 1) {
			dfs(adj,vis,i);
		}
	}

	return 0;
}