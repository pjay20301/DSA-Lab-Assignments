#include <stdio.h>
#include <stdbool.h>  
#include <stdlib.h>  
struct node{  
    int data;  
    struct node *left;  
    struct node *right;  
};  
struct node* createNode(int data){  
    struct node* newNode = (struct node *)malloc(sizeof(struct node));  
    newNode->data = data;  
    newNode->left = NULL;  
    newNode->right = NULL;  
      
    return newNode;  
}  
struct node *root = NULL;  
struct node *temp1=NULL;
static bool flag = false;  
void searchNode(struct node *temp, int value){  
    if(root == NULL){  
        printf("Tree is empty\n");  
    }  
    else{  
        if(temp->data == value){  
            flag = true; 
            temp1=temp;
             return;  
        }  
        if(flag == false && temp->left != NULL){  
        searchNode(temp->left, value);  
        }  
        if(flag == false && temp->right != NULL){  
        searchNode(temp->right, value);  
        }  
    }  
}  
void zizagtraversal(struct node* ptr,int n)
{
    // if null then return
    if (ptr==NULL)
        return;
    struct node* currentlevel[n];
    struct node* nextlevel[n];
    int top1=-1;
    int top2=-1;
    currentlevel[0]=ptr;
    top1++;
    bool lefttoright = true;
    while (top1!=-1) {
        struct node *temp=currentlevel[top1];
        top1--;
 
        if (temp!=NULL) {
            printf("%d ",temp->data);
            if (lefttoright) {
                if (temp->left)
                {
                    top2++;
                    nextlevel[top2]=temp->left;
                }
                if (temp->right)
                {
                    top2++;
                    nextlevel[top2]=temp->right;
                }
            }
            else {
                if (temp->right)
                {
                    top2++;
                    nextlevel[top2]=temp->right;
                }
                if (temp->left)
                {
                    top2++;
                    nextlevel[top2]=temp->left;
                }
            }
        }
 
        if (top1==-1) {
            lefttoright = !lefttoright;
            for(int i=0;i<=top2;i++)
            {
                currentlevel[i]=nextlevel[i];
            }
            top1=top2;
            top2=-1;
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    root=createNode(a[0]);
    int x,y;
    char c;
    struct node *tempx=NULL;
    struct node *tempy=NULL;
    for(int i=0;i<n-1;i++)
    {
        scanf("%d %d %c",&x,&y,&c);
        searchNode(root,a[x]);
        if(flag)
        {
            tempx=temp1;
            flag=false;
        }
        else
        {
            tempx=createNode(a[x]);
        }
        searchNode(root,a[y]);
        if(flag)
        {
            tempy=temp1;
            flag=false;
        }
        else
        tempy=createNode(a[y]);
        if(c=='L')
        {
            tempx->left=tempy;
        }
        else
        tempx->right=tempy;
    }
   zizagtraversal(root,n);
    return 0;
}
