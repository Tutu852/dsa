#include<iostream>
using namespace std;

struct node{
    int key;
    struct node *left , *right;
   
};

// A Utility funtion to create a new BST node

struct node* newNode(int item){
    struct node* temp = new struct node;
    temp->key =item;
    temp->left = temp->right = NULL;
    return temp;
};

//A Utility function to insert
// a new node with given key in BST
struct node* insert(struct node* node, int key) {
    /* If the tree is empty, return a new node */
    if (node == NULL) 
        return newNode(key);

    //oherwise recure dowm the tree
    if (key < node->key){
        node->left  = insert(node->left, key);
    }else if(key > node->key){
        node->right = insert(node->right, key);
    }
    return node;
}

//Utilit function to search a key in a BST
struct node* search(struct node* node, int key) {
    //base case : root is null or key is present at root
    if(node == NULL || node->key == key){
        return node;
    }
    //key is greater the root's key
    if(key < node->key){
        return search(node->left, key);
    }
}



void printLL(node* head){
    while(head){
        cout<<head->key<<" ";
        head = head->right;
    }
}

void in(node* root,node* &prev){
    if(root == NULL) return;
    in(root->left,prev);
    prev->left = NULL;
    prev->right =root;
    prev= root;
    in(root->right,prev);
}

node* flatten(node*root){
    node*dummy = newNode(-1);
    node*prev = dummy;
    in(root,prev);
    prev->left = prev->right = NULL;
    root=dummy->right;
    return root;
}

int main(){
    struct node* root = NULL;
    root= insert(root,5);
    insert(root,3);
    insert(root,2);
    insert(root,4);
    insert(root,7);
    insert(root,6);
    insert(root,8);
    root= flatten(root);
    printLL(root);
}