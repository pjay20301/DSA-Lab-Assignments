#include <stdio.h>
#include <stdlib.h>


#define N 1000
#define MOD 1000000007


int a[N], b[N], c[N];
int k = 0;
struct Node {

	int value;
	struct Node* left;
	struct Node* right;
};

struct Node* root = NULL;
struct Node* ptr = NULL;
int check = 0;

struct Node* createNode(int x) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  
    newNode->value = x;  
    newNode->left = NULL;  
    newNode->right = NULL;  
      
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

void Inorder(struct Node* node) {

    if (node == NULL)
        return;
 
    Inorder(node->left);
    c[k++] = node -> value;
    Inorder(node->right);
} 

void Preorder(struct Node* node) {
	
    if (node == NULL)
        return;
 
    a[k++] = node -> value;
    Preorder(node->left);
    Preorder(node->right);
} 

void Postorder(struct Node* node) {
	
    if (node == NULL)
        return;
 
    Postorder(node->left);
    Postorder(node->right);
    b[k++] = node -> value;
} 

int fun(int a[], int b[], int c[], int n) {
	int ans = 0;

	for(int i = 0; i < n; i++) {
		if(a[i] >= b[i]) 
			ans += ((a[i]-b[i])*c[i])%MOD;
		else
			ans += ((b[i]-a[i])*c[i])%MOD;
	}
	return ans;
}
int main() {

	int n;
	scanf("%d",&n);

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
        }
        
		if(ch == 'L') {
			xNode -> left = yNode;
		} else {
			xNode -> right = yNode;
		}
	}

	Inorder(root); k = 0;
	Preorder(root); k = 0;
	Postorder(root);
	int ans = fun(a,b,c,n);
	printf("%d",ans);

}