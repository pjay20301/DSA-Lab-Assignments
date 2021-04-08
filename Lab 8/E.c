#include <stdio.h>
#define N 1000

int post[N], k = 0;

int linear_serach(int in[], int x, int n) {
	for(int i = 0; i < n; i++) {
		if(in[i] == x)
			return i;
	}
	return -1;
}
void postOrder(int in[], int pre[], int n) {

	int root = linear_serach(in, pre[0], n);

	if(root != 0)
		postOrder(in, pre+1, root);
	if(root != n-1)
		postOrder(in+root+1, pre+root+1, n-root-1);

	post[k++] = pre[0];
}
int main() {
	int n;
	scanf("%d",&n);

	int in[n], pre[n];
	for(int i = 0; i < n; i++) {
		scanf("%d",&in[i]);
	}

	for(int i = 0; i < n; i++) {
		scanf("%d",&pre[i]);
	}

	postOrder(in, pre, n);

	for(int i = 0; i < n; i++) {
		printf("%d ",post[i]);
	}
	return 0;
}