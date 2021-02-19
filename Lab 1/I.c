#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void append(struct Node** head, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    struct Node* temp;
    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL) 
        *head = newNode;
    else {
        temp = *head;
        while(temp->next != NULL) 
            temp = temp->next;
        temp->next = newNode;
    }
}

void reverseLinkedList(struct Node** head) {
    struct Node* next = NULL;
    struct Node* prev = NULL;
    struct Node* current = *head;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void printLinkedList(struct Node* head) {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
int main() {
    int check = 1;
    struct Node* head = NULL;
    while (check == 1) {
        int a;
        scanf("%d",&a);
        if(a != -1) {
            append(&head,a);
        } else break;
    }
    reverseLinkedList(&head);
    printLinkedList(head);

}