#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
    char data;
    struct Node *prev;
    struct Node *next;
};
 
void append(struct Node** head, char c) {

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode -> data = c;
    newNode -> next = *head;
    newNode -> prev = NULL;

    if((*head) != NULL) (*head) -> prev = newNode;
    *head = newNode;  
}

bool check(struct Node *left) {
    if(left == NULL) return true;
    struct Node *right = left;
    while(right->next != NULL) {
        right = right->next;
    }
    while(left != right) {
        if((left) -> data != (right) -> data) {
            return false;
        }

        left = left -> next;
        right = right -> prev;
    }
    return true;
}

int main() {
    int n;
    scanf("%d\n",&n);
    struct Node *head = NULL;
    for(int i = 0; i <= n+1; i++) {
        char c;
        scanf("%c", &c);
        append(&head,c);
    }

    if(check(head) == true) printf("PALINDROME");
    else printf("NOT A PALINDROME");
    return 0;
}