#include <stdio.h>
#include <string.h>

int main() {
	int A,P,C;
	scanf("%d %d %d",&A,&P,&C);

	int p[1000]={},a[1000]={},c[1000]={},vis[1000]={};
	for(int i = 0; i < P; i++) {
		scanf("%d",&p[i]);
	}

	for(int i = 0; i < C; i++) {
		int u,v;
		scanf("%d %d",&u,&v);
		c[v]++;
	}

	for(int i = 0; i < P; i++) {
		if(vis[p[i]] == 0) {
			a[p[i]] = c[i];
			vis[p[i]] = 1;
		} else {
			if(c[i] < a[p[i]]) {
        	a[p[i]] = c[i];
        }
		}
   
	}
	for(int i = 0; i < A; i++) {
		printf("%d ",a[i]);
	}
}