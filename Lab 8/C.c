#include <stdio.h>
#include <stdlib.h>

struct treeNode {

	int value;
	struct treeNode* left;
	struct treeNode* right;
};

struct treeNode* root = NULL;
struct treeNode* ptr = NULL;
int check = 0;

struct treeNode* createtreeNode(int x) {
	struct treeNode* newtreeNode = (struct treeNode*)malloc(sizeof(struct treeNode));  
    newtreeNode->value = x;  
    newtreeNode->left = NULL;  
    newtreeNode->right = NULL;  
      
    return newtreeNode;  
}

void searchTreeNode(struct treeNode *temp, int x){  

    if(root == NULL){  
		return; 
    }  else {  

        if(temp->value == x){  
            check = 1; 
            ptr=temp;
             return;  
        }  
 
        if(check == 0 && temp->left != NULL){  
        searchTreeNode(temp->left, x);  
        }  
 
        if(check == 0 && temp->right != NULL){  
        searchTreeNode(temp->right, x);  
        }  
    }  
}

struct stackNode {

  struct treeNode *tree;
  struct stackNode *next;
};

void push(struct stackNode** top_ref, struct treeNode *tree) {

  struct stackNode* newTreeNode = (struct stackNode*) malloc(sizeof(struct stackNode));
 
  if(newTreeNode == NULL) {
     exit(0);
  }           
 
  newTreeNode->tree  = tree;
 
  newTreeNode->next = (*top_ref);  
 
  (*top_ref)    = newTreeNode;
}
 
int isEmpty(struct stackNode *top) {

   return (top == NULL)? 1 : 0;
}  
 
struct treeNode *pop(struct stackNode** top_ref) {

  struct treeNode *res;
  struct stackNode *top;
 
  if(isEmpty(*top_ref)) {
    exit(0);
  }
  else {

     top = *top_ref;
     res = top->tree;
     *top_ref = top->next;
     free(top);
     return res;
  }
}
 

int main() {
    int n;
    scanf("%d",&n);

    int t[n];
    for(int i = 0 ; i < n; i++) {
        scanf("%d",&t[i]);
    }
    root = createtreeNode(t[0]);
    int x, y;
    char ch;
    struct treeNode *xtreeNode = NULL;
    struct treeNode *ytreeNode = NULL;
    for(int i = 0; i < n-1; i++) {

        scanf("%d %d %c",&x,&y,&ch);

        searchTreeNode(root, t[x]);
        if(check) {

            xtreeNode = ptr;
            check = 0;
        }
        else {

            xtreeNode=createtreeNode(t[x]);
        }
        searchTreeNode(root, t[y]);
        if(check) {

            ytreeNode = ptr;
            check = 0;
        }
        else {
            ytreeNode = createtreeNode(t[y]);
        }
        
        if(ch == 'L') {
            xtreeNode -> left = ytreeNode;
        } else {
            xtreeNode -> right = ytreeNode;
        }
    }

    struct stackNode* stack = NULL;
    struct treeNode* current = root;
    check = 0;

    while(!check)  {

        if(current != NULL) {

            push(&stack, current);
            current = current -> left;

        } else {

            if(!isEmpty(stack)) {

                current = pop(&stack);
                printf("%d ",current -> value);

                current = current -> right;

            } else 
                check = 1;
        }
    }

    return 0;
}