#include <stdio.h>
#include <stdlib.h>
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
	int a[n];
	for(int i = 1; i <= n; i++) {
		scanf("%d",&a[i]);

		if(isEmpty(stack)) {
			push(stack, i);
			printf("-1 ");
		} else {
			while(a[peek(stack)] >= a[i] && !isEmpty(stack)) {
				pop(stack);
			}
			printf("%d ",peek(stack));
			push(stack, i);
		}
	}

	return 0;
}