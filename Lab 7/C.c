#include <stdio.h>
#include <stdlib.h>

#define max(a,b) ((a>b) ? a : b)
#define min(a,b) ((a<b) ? a : b)
struct Stack {
	int top;
	int size;
	int *a;
};

struct Stack* createStack(int size) {
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
	stack -> size = size;
	stack -> top = -1;
	stack -> a = (int *) malloc((stack -> size) * sizeof(int ));
	return stack;
}

int isFull(struct Stack* stack) {
	return stack -> top == stack -> size -1;
}

int isEmpty(struct Stack* stack) {
	return stack -> top == -1;
}

void push(struct Stack* stack, int x) {
	if(isFull(stack)) {
		return;
	}
	stack -> a[++stack -> top] = x;
}

int pop(struct Stack* stack) {
	if(isEmpty(stack)) 
		return -1;
	return stack -> a[stack -> top--];
}

int peek(struct Stack* stack) {
	if(isEmpty(stack)) 
		return -1;
	return stack -> a[stack -> top];
}

int main() {
	int m, n;
	scanf("%d %d",&n, &m);
	int a[n][m];
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			scanf("%d",&a[i][j]);
		}
	}
	int enemy[n][m];
	for(int j = 1; j <= m; j++) {

		struct Stack* stack = createStack(n);

		for(int i = 1; i <= n; i++) {
			if(a[i][j] == 0) {
				enemy[i][j] = 0;
				push(stack, i);
			} else {
				if(isEmpty(stack))
					enemy[i][j] = i;
				else
				    enemy[i][j] = i - peek(stack);
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {

		struct Stack* stack = createStack(m);
		int mn = enemy[i][1];
		for(int j = 1; j <= m; j++) {
			if(enemy[i][j] <= mn) {
				push(stack, mn);
				ans = max(ans, j*enemy[i][j]);
			} else {
				while(peek(stack) >= enemy[i][j] && !isEmpty(stack)) {
					mn = min(mn, peek(stack));
					pop(stack);
				} int len;
				if(isEmpty(stack))
					len = 1;
				else 
					len = j - peek(stack) + 1;
				ans = max(ans, len*enemy[i][j]);

			}
		}
	}
	printf("%d",ans);
 
	return 0;
}