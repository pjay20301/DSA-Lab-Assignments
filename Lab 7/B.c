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
	int n;
	scanf("%d",&n);

	struct Stack* stack = createStack(n);
	int a[n], vol = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d",&a[i]);

		if(isEmpty(stack)) {
			push(stack, i);
			vol = max(vol, i*a[i]);
		} else { 
			int mn = a[i];
			while(a[peek(stack)] >= a[i] && !isEmpty(stack)) {
				mn = min(mn, peek(stack));
				pop(stack);
			} int len;
			if(isEmpty(stack))
				len = 1;
			else 
				len = i - peek(stack) + 1;
			vol = max(vol, len*mn);
			push(stack, i);
		}
	}

	printf("%d",vol);

	return 0;
}