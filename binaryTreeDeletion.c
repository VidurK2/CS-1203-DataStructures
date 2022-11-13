#include<stdio.h>
#include<stdlib.h>

//Binary tree has two parts - left and right along with the value of the element its on
struct node {
    int val;
    struct node *left;
    struct node *right;
};

struct node *deleteLeaf(struct node *root, int val)
{

    //If the root is NULL, nothing happens and it just returns NULL
    if(root == NULL) {
        return NULL;
    }

   
    //If value is less than root, it is to the left of node
    else if(val < root->val) {
        root->left = deleteLeaf(root->left,val);
    }
    
    
    //If value is more than root, it is to the right of node
    else if(val > root->val) {
        root->right = deleteLeaf(root->right,val);
    }
    
    
    //Else, delete the node that it actually lands on after recusion
    else {
   
        
        //When both left and right are NULL, we just free the root we land on and return NULL
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
   
        
        //When the left is NULL, then we free the root and return the right element of it
        else if(root->left == NULL)
        {
            struct node *tmp = root->right;
            free(root);
            return tmp;
        }

        
        //When the right is NULL, then we free the root and return the left element of it
        else if(root->right == NULL)
        {
            struct node *tmp = root->left;
            free(root);
            return tmp;
        }

        
        //When neither are NULL, then we find the minimum value of the right side
        //Then we replace the value with that minimum value
        //Then we recursively call this delete function
        else
        {
            int valMin;
            struct node *tmp = root;

    
            while(tmp->left != NULL){
                tmp = tmp->left;
                
            }
            
            valMin = tmp->val;
            
            root->val = valMin;
            root->right = deleteLeaf(root->right,valMin);
        }

    }

    return root;
}

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
    
    int delEl;
    printf("\n Enter the element you want to delete : ");
    scanf("%d", &delEl);
    
    deleteLeaf(root, delEl);
    
    printf("\n Binary Tree after deletion :- \n");
    treePrint(root);

    return 0;
}
