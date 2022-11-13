#include<stdio.h>
#include<stdlib.h>

//Binary tree has two parts - left and right along with the value of the element its on
struct node {
    int val;
    struct node *left;
    struct node *right;
};

//Prints the nodes until it reaches null
void treePrint(struct node *root) {
    
    if (root != NULL) {
        
        //Recursively goes to left and right elements
        treePrint(root->left);
        printf("%d\n", root->val);
        treePrint(root->right);
        
    }
}


//Inserts a node
struct node* leafInsert(struct node* root, int x)
{
    //If the root is null, it inserts the root element
    if (root == NULL) {
        struct node *temp;
        temp = (struct node *)malloc(sizeof(struct node));
        
        //Sets root value to x and the left right values to NULL
        temp->val = x;
        temp->left = NULL;
        temp->right = NULL;
        
        return temp;
    }
    
    //If x is smaller, it goes to left
    else if (x < root->val) {
        root->left = leafInsert(root->left, x);
    }
    
    //If x is bigger, it goes to right
    else if (x > root->val) {
        root->right = leafInsert(root->right, x);
    }
    
    return root;
}

//Main function for input and calling functions
int main() {

    struct node *root = NULL;
    int x;
    printf("Enter the root element : ");
    scanf("%d", &x);
    
    root = leafInsert(root, x);
    
    int num;
    printf("Enter number of elements you want to insert : ");
    scanf("%d", &num);
    int A[num];
    
    for (int i=0; i<num; i++) {
        int elem;
        printf("Enter an element : ");
        scanf("%d", &elem);
        A[i] = elem;
        leafInsert(root, A[i]);
    }


    treePrint(root);

    return 0;
}
