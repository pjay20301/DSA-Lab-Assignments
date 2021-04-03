#include <stdio.h>
#include <string.h>
#include <stdlib.h>



struct Node {
	int data;
	struct Node* next;
};

struct Node* head = NULL;


void addNode(struct Node** head, int num)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
  
    struct Node *last = *head; 
   
    newNode->data  = num;
  
    newNode->next = NULL;
  
    if (*head == NULL)
    {
       *head = newNode;
       return;
    }  
       
    while (last->next != NULL)
        last = last->next;
   
    last->next = newNode;
    return;    
}
void deleteNode(struct Node** head, int num) {
	struct Node *temp = *head, *prev;
 
    if (temp != NULL && temp->data == num) {
        *head = temp->next; 
        free(temp); 
        return;
    }
 
    while (temp != NULL && temp->data != num) {
        prev = temp;
        temp = temp->next;
    }
 
    if (temp == NULL)
        return;
 
    prev->next = temp->next;
 
    free(temp); 
}
int query(struct Node* head_ref, int num) {
	int ans = 0;
	while(head_ref != NULL) { 

		int check = 1;
		int k = head_ref -> data;

		while(k!= 0 && num != 0) {

			if((k%10)%2 != (num%10)%2) {

				check = 0;
				break;
			}
			k /= 10;
			num /= 10;
		}
		while(k>0) {

			if((k%10)&1 == 1) {
				check = 0;
				break;
			} k /= 10;
		}
		while(num>0) {

			if((num%10)&1 == 1) {
				check = 0;
				break;
			} num /= 10;
		}
		head_ref = head_ref -> next;

		if(check == 1)
			ans++;
	}
	return ans;
}
int main() {
	int n;
	scanf("%d",&n);

	int m;

	for(int i = 0; i < n; i++) {
		char operation[10];
		scanf("%s %d",operation,&m);

		if(operation[0] == 'a') {
			addNode(&head, m);

		}
		else if(operation[0] == 'd') {
			deleteNode(&head, m);

		}
		else {
			int x = query(head, m);
			printf("%d",x);
		}
	}

	return 0;
}