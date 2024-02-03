//BINARY SEARCH TREE

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int data);
Node* insert(Node* root, int data);
void printInorder(Node* node);
void printPreorder(Node* node);
void printPostorder(Node* node);
Node* binarySearch(Node* root, int key);
Node* delete(Node* root, int key);

//Node creating function for tree
Node* createNode(int data)
{
    Node* node;
    node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main()
{
    Node *root = NULL;
    int key, choice;

    do
    {
        printf("\nChoose:\n1. Insert\n2. Pre-order Traversal\n3. In-order Traversal\n4. Post-order Traversal\n5. Delete\n0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter key to be added: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            
            case 2:
                printPreorder(root);
                printf("\n");
                break;

            case 3:
                printInorder(root);
                printf("\n");
                break;

            case 4:
                printPostorder(root);
                printf("\n");
                break;

            case 5:
                printf("Enter key to be deleted: ");
                scanf("%d", &key);
                root=delete(root, key);
                break;

            case 0:
                break;
                
            default:
                break;
        }
    }while(choice != 0);
    return 0;
}

//function to insert a new node in tree
Node* insert(Node* root, int data)
{
    if(root == NULL)
    {
        root = createNode(data);
    }
    else
    {
        if(data < root->data)
        {
            root->left = insert(root->left, data);
        }
        else
        {
            root->right = insert(root->right, data);
        }
    }
    return root;
}

//function for left node right traversal (LNR)
void printInorder(Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left); // first recur on left child
    printf("%d ",node->data); // then print the data of node
    printInorder(node->right); // now recur on right child
}

//function for node left right traversal (NLR)
void printPreorder(Node* node)
{
    if (node == NULL)
        return;
    printf("%d ",node->data); //first print the data of node
    printPreorder(node->left); //then recur on left child
    printPreorder(node->right); //now recur on right child
}

//function for left right node traversal (LRN)
void printPostorder(Node* node)
{
    if (node == NULL)
        return;
    printPostorder(node->left); //first recur on left child
    printPostorder(node->right); //then recur on right child
    printf("%d ",node->data); //now print data of node
}

//function for binary search
Node* binarySearch(Node* root, int key)
{
    if(root == NULL)
    {
        return NULL;
    }
    else if(root->data == key)
    {
        return root;        
    }
    else if(key < root->data)
    {
        return binarySearch(root->left, key);
    }
    else
    {
        return binarySearch(root->right, key);
    }
}

//function to delete a node from tree
Node* delete(Node* root, int key)
{
    struct Node* temp;
    if(root == NULL)
    {
        return root;
    }
    if(key < root->data)
    {
        root->left = delete(root->left, key);
    }
    else if(key > root->data)
    {
        root->right = delete(root->right, key);
    }
    else
    {
        if(root->left == NULL && root->right == NULL)
        { //if leaf node
            free(root);
            return NULL;
        }
        else if(root->left != NULL && root->right == NULL)
        { //node with degree 1 left child
            temp = root;
            root = root->left;
            free(temp);
            return root;
        }
        else if(root->left == NULL && root->right != NULL)
        { //node with degree 1 having right child
            temp = root;
            root = root->right;
            free(temp);
            return root;
        }
        else
        { //node with degree 2
            temp = root->right;
            while (temp && temp->left != NULL)
                temp = temp->left;
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
            
        }
    }
    return root;
}
