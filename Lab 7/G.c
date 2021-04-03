#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* prev;
struct Node* next;
};

struct Node *tail = NULL;
struct Node *head = NULL;

struct Node* getNewNode(int x) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode -> data = x;
    newNode -> prev = NULL;
    newNode -> next = NULL;
    return newNode;
}

void append(int x) {
    struct Node* newNode = getNewNode(x);
    if(tail == NULL) {
        tail = newNode;
        head = newNode;
         tail -> next = NULL;
         tail -> prev = NULL;
         return;
    }
    tail -> next = newNode;
    newNode -> prev = tail;
    tail = newNode;
    newNode -> next = NULL; 
    return;
}

void fun(struct Node** ptr, int n) {
	int k = n;
	struct Node* temp = *ptr;
	struct Node *left, *right;

	while(k--) {
		temp -> data = (temp -> data)*n;
			temp = temp -> next;
	}
	if(temp == NULL)
		temp = tail;
	else
		temp = temp->prev;
	right = temp;
	left = *ptr;
	*ptr = temp;
	while(left < right) {
		int tmp1 = left->data;
		left->data = right->data;
		right->data = tmp1;

		right = right -> prev;
		left = left -> next;
	}
}


int main() {
	int n, k, x;
	scanf("%d %d",&n,&k);


	for(int i = 0; i < n; i++) {
		scanf("%d",&x);
		append(x);
	}
	struct Node* ptr = head;
	for(int i = 0; i < k; i++) {
		scanf("%d",&x);
		fun(&ptr, x);
		if(ptr->next != NULL)
		ptr = ptr->next;

	}

	while(head != NULL) {
		printf("%d ",head->data);
		head = head -> next;
	}

	return 0;
}