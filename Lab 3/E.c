#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Stack {
    int top;
    int capacity;
    int* array;
};
struct Stack1 {
    int top;
    int capacity;
    char* array;
};
 
struct Stack* createStack(int capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}
struct Stack1* createStack1(int capacity)
{
    struct Stack1* stack = (struct Stack1*)malloc(sizeof(struct Stack1));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}
 
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}


void push(struct Stack* stack, int item)
{
    stack->array[++stack->top] = item;
}
void push1(struct Stack1* stack, char item)
{
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}
char pop1(struct Stack1* stack)
{
    return stack->array[stack->top--];
}

int main() {
	int n, ans = 0;
	scanf("%d",&n);
	struct Stack1* commands = createStack1(n);
	struct Stack* values = createStack(n);
	for(int i = 0; i < n; i++) {
		char command[5];
		int x;
		scanf("%s",command);
		if(command[0] != 'E') {
			scanf("%d",&x);
            push1(commands,command[0]);
            push(values,x);
		} else {
			while(pop1(commands) != 'L') {
				ans += pop(values);
			}
			ans *= pop(values);
		}
	}
	while(!isEmpty(values)) {
		ans += pop(values);
	}
	printf("%d",ans);
}