#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a,b) ((a>b)?a:b)


struct Node {

	int value;
	struct Node* left;
	struct Node* right;
    struct Node* parent;
};

struct Node* root = NULL;
struct Node* ptr = NULL;
int check = 0;

struct Node* createNode(int x) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  
    newNode->value = x;  
    newNode->left = NULL;  
    newNode->right = NULL; 
    newNode->parent = NULL;  
    return newNode;  
}

void searchNode(struct Node *temp, int x){  

    if(root == NULL){  
		return; 
    }  else {  

        if(temp->value == x){  
            check = 1; 
            ptr=temp;
            return;  
        }  
 
        if(check == 0 && temp->left != NULL){  
        searchNode(temp->left, x);  
        }  
 
        if(check == 0 && temp->right != NULL){  
        searchNode(temp->right, x);  
        }  
    }  
}

void delete(struct Node* t, int x) {
    struct Node* temp = t;

    if(root == NULL){  
        return; 
    } else {  

        if(temp->value == x){  
            
            temp = temp->parent;
            if((temp->left)->value == x)
                temp->left = NULL;
            else
                temp->right = NULL;    
            return;  
        }  
 
        if(temp->left != NULL){  
            delete(temp->left, x);  
        }  
 
        if(temp->right != NULL){  
            delete(temp->right, x);  
        }  
    }
}

void swap(struct Node* temp, int x, int y) {

    searchNode(temp, x);

    struct Node* ptr1 = ptr;

    check = 0;
    searchNode(temp, y);

    struct Node* ptr2 = ptr;


    struct Node* temp1 = ptr1;
    struct Node* temp2 = ptr2;

     temp1->parent = ptr2->parent;
     temp2->parent = ptr1->parent;

     temp1 = temp1->parent;
     temp2 = temp2->parent;

    if(temp1->left == ptr1) {
        temp1->left = ptr2;
    } else {

        temp1->right = ptr2;
    }

    if(temp2->left == ptr2) {

        temp2->left = ptr1;
    } else {

        temp2->right = ptr1;
    }
    ptr1 = temp1;
    ptr2 = temp2;

}

int height(struct Node* node)
{
    if (node == NULL)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}
int diameter(struct Node* tree)
{

    if (tree == NULL)
        return 0;
 
    int lheight = height(tree->left);
    int rheight = height(tree->right);
 
    int ldiameter = diameter(tree->left);
    int rdiameter = diameter(tree->right);
 
    return max(lheight + rheight,
               max(ldiameter, rdiameter));
}

int main() {

	int n, m;
	scanf("%d %d",&n, &m);

	int t[n];
	for(int i = 0 ; i < n; i++) {
		scanf("%d",&t[i]);
	}
	root = createNode(t[0]);
	int x, y;
	char ch;
	struct Node *xNode = NULL;
    struct Node *yNode = NULL;
	for(int i = 0; i < n-1; i++) {

		scanf("%d %d %c",&x,&y,&ch);

		searchNode(root, t[x]);
		if(check) {

            xNode = ptr;
            check = 0;
        }
        else {

            xNode=createNode(t[x]);
        }
        searchNode(root, t[y]);
        if(check) {

            yNode = ptr;
            check = 0;
        }
        else {
        	yNode = createNode(t[y]);
            if(yNode->parent == NULL)
                yNode->parent = xNode;
        }
        
		if(ch == 'L') {
			xNode -> left = yNode;
		} else {
			xNode -> right = yNode;
		}
	}

    char command[7]; 
    int a, b;
    ptr = root;
    for(int i = 0; i < m; i++) {
        scanf("%s",command);

        if(command[0] == 'D') {
            scanf("%d",&a);
            delete(root, a);
        } else {

            scanf("%d %d",&a,&b);
            swap(root, a, b);
        }
    }
    int d = diameter(root);
    printf("%d",d);

}