#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *left;
    struct node *right;
};

struct node *newNode(int val)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return (node);
}
struct node *lca(struct node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
  
    if (root->val > n1 && root->val > n2)
        return lca(root->left, n1, n2);

    if (root->val < n1 && root->val < n2)
        return lca(root->right, n1, n2);

    return root;
}
void printPreorder(struct node *node)
{
    if (node == NULL)
        return;

    printf("%d ", node->val);

    printPreorder(node->left);

    printPreorder(node->right);
}


int main()
{
    int n, q, num1, num2, parent, child;
    scanf("%d %d", &n, &q);
   int* arr=(int *) malloc(n*sizeof(int));
    
    char c;
    struct node *A[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        A[i] = newNode(arr[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d %d %c", &parent, &child, &c);
        if (c == 'L')
        {
            A[parent]->left = A[child];
        }
        else
        {
            A[parent]->right = A[child];
        }
    }


    struct node *te = (struct node *)malloc(sizeof(struct node));
    te->val = 0;
    te->left = NULL;
    te->right = NULL;
    int atr[q];
    int count=0;
    for (int i = 0; i < q; i++)
    {
        scanf("%d %d", &num1, &num2);
         te = lca(A[0], A[num1]->val, A[num2]->val);
        for (int j = 0; j < n; j++)
        {
            if (te->val == A[j]->val)
            {
                atr[count++]=j;
            }
        }
    }

    for(int i=0;i<q;i++)
        printf("%d ",atr[i]);
    getchar();
}
