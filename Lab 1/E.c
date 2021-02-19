#include<stdio.h>
#include<stdlib.h>

struct Node {
char data;
struct Node* prev;
struct Node* next;
};

struct Node *tail = NULL;
struct Node *head = NULL;

struct Node* getNewNode(char c) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode -> data = c;
    newNode -> prev = NULL;
    newNode -> next = NULL;
    return newNode;
}


void prepend(char c) {
    struct Node* newNode = getNewNode(c);
    if(head == NULL) {
        tail = newNode;
        head = newNode;
         head -> next = NULL;
         head -> prev = NULL;
         return;
    }
    head -> prev = newNode;
    newNode -> next = head;
    newNode -> prev = NULL;
    head = newNode; 
    return;
}

void append(char c) {
    struct Node* newNode = getNewNode(c);
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


void LeftShift() {
    append('0');
    head = head -> next;
    head -> prev = NULL;
    return; 
}


void LeftRotate() {
    struct Node* newNode = getNewNode(head->data);
    append(head->data);
    head = head -> next;
    head -> prev = NULL;
    return;
}


void RightShift() {
    prepend('0');
    tail = tail -> prev;
    tail -> next = NULL;
    return;
}
void RightRototate() {
    prepend(tail -> data);
    tail = tail -> prev;
    tail -> next = NULL;  
}
void Increase() {
    int carry = 1;
    struct Node* ptr = tail;
    while(ptr != NULL) {
        if(ptr -> data == '0') {
            if(carry == 1) 
               ptr -> data = '1';
           else 
               ptr -> data = '0';
           carry = 0;
        } else {
            if(carry == 1) 
                ptr -> data = '0';
            else 
                ptr -> data = '1', carry = 0;
        }

        ptr = ptr -> prev;
    }
    return;
}
void Decrease() {
    int carry = 1;
    struct Node* ptr = tail;
    while(ptr != NULL) {
        if(ptr -> data == '0') {
            if(carry == 1)
                ptr -> data = '1';
            else 
                ptr -> data = '0';
        } else {
            if(carry == 1) 
                ptr -> data = '0', carry = 0;
            else 
                ptr -> data = '1';
        }
        ptr = ptr -> prev;
    }
    return;
}
void printlist() {
    struct Node* left = head;
    while(left != NULL) {
        printf("%c",left->data);
        left = left->next;
    }
    printf("\n");
}
int main() {

    
    char a[1005] = {};
    int check = 1;
    while(check == 1) {
        char ch;
        scanf("%c",&ch);
        if(ch == '1' || ch == '0') 
            append(ch);
        else break;
    }
    int m;
    scanf("%d",&m);
    for(int i = 0; i < m; i++) {
        scanf("\n");
        char ch[4] = {};
        scanf("%[LRSINCDE]s",ch);
        if(ch[0] == 'L') {
            if(ch[1] == 'R') LeftRotate();
            else if(ch[1] == 'S') LeftShift();
        } else if(ch[0] == 'R') {
            if(ch[1] == 'R') RightRototate();
            else if(ch[1] == 'S') RightShift();
        } else if(ch[0] == 'I') Increase();
        else Decrease();
    }
    printlist();
    return 0;
}