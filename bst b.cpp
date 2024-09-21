#include<bits/stdc++.h>
using namespace std;
struct Node{
         int data;
         struct Node *left, *right;
         Node(int data)
         {
             this -> data = data;
             left = NULL;
             right  = NULL;
         }
};
typedef struct Node sn;
sn* insert(sn* node, int data)
{
    if(node == NULL)
        return new Node(data);
    if(data < node -> data)
        node->left = insert(node->left, data);
    else if(data > node->data)
        node->right = insert(node->right, data);

    return node;
}

sn* findMin(sn* node)
{
    while(node && node->left != NULL)
        node = node-> left;

    return node;
}

sn* deleteNode(sn* node, int key)
{
    if(node == NULL)
        return node;
    if(key < node-> data)
        node->left = deleteNode(node->left, key);
    else if(key > node->data)
        node->right = deleteNode(node->right, key);
        else
        {
        //node with single children.
            if(node->left == NULL)
            {
                sn* temp = node->right;
                delete node;
                return temp;
            }
            else if(node->right == NULL)
            {
                sn* temp = node->left;
                delete node;
                return temp;
            }
            // node with two children
            sn* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;

}

sn* search(sn* node, int key)
{
    if(node == NULL || node->data == key)
        return node;

    if(key<node->data)
        return search(node->left, key);
    return search(node->right, key);
}

void preorderTraversal(sn *node)
{
    if(node == NULL)
        return;
    printf("%d -> ", node->data);
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

void inorderTraversal(sn *node)
{
    if(node == NULL)
        return;
    inorderTraversal(node->left);
    printf("%d -> ", node->data);
    inorderTraversal(node->right);

}

void postorderTraversal(sn* node)
{
    if(node == NULL)
        return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    printf("%d -> ", node->data);
}

int main()
{
    sn* node = NULL;
    int n,  data;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>data;
        node = insert(node, data);
    }
    insert(node, 8);
    printf("Pre-order Traversal: \n");
    preorderTraversal(node);
    printf("\n");
    printf("Post-order Traversal: \n");
    postorderTraversal(node);
    printf("\n");
    printf("In-order Traversal: \n");
    inorderTraversal(node);
    printf("\n");

    int key;
    cin>>key;
    sn* found = search(node, key);
    if(found != NULL)
        cout<< "Node "<< key<< " is found in the tree\n";
    else
      cout<< "Node "<< key<< " is not found in the tree\n";

      node = deleteNode(node, key);
      printf("In order Traversal after deletion: \n");
      inorderTraversal(node);
    return 0;
}
