#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};
    //it returns root node if the created tree
    Node* createTree(){
        cout<<"Enter the value for node" <<endl;
        int data;
        cin>>data;

        if(data == -1){
            return NULL;
        }
        //step1: create Node
        Node* root = new Node(data);
        //Create left subtree
        cout<<"left of Node " <<root->data <<endl;
        root->left = createTree();
        //reate right subtree
        cout<<"right of Node " <<root->data <<endl;
        root->right = createTree();
        return root;
    }


    void preOrderTraversal(Node* root){
        //base case
        if(root == NULL){
            return;
        }
        //N L R
        cout<< root->data <<" ";

        //L using recursion
        preOrderTraversal(root->left);
        //R using recursion
        preOrderTraversal(root->right);
    }

    void inOrderTraversal(Node* root){
        if(root == NULL){
            return;
        }
        //L using reursion
        inOrderTraversal(root->left);
        //  N 
        cout<<root->data<<" ";

        //R using recurion
        inOrderTraversal(root->right);
    }
    void postOrderTraversal(Node* root){
        if(root == NULL){
            return;
        }
        // L R N 
        //L using reursion
        postOrderTraversal(root->left);

        //R using recurion
        postOrderTraversal(root->right);
        //  N 
        cout<<root->data<<" ";
    }

void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);


    //asli traversal start krete he
    while(!q.empty()){
        Node* front = q.front();
        q.pop(); 

        if(front == NULL) {
            cout<<endl;
           if(!q.empty()){
             q.push(NULL);
           }
        }else{

        cout<<front->data <<" ";


        if(front->left != NULL){
            q.push(front->left);
        }
        if(front->right != NULL){
            q.push(front->right);
        }
        }

    }
}
int main(){

Node* root  = createTree();
// cout<<root->data<<endl;
cout<<"Printing preOder : " ;
preOrderTraversal(root);
cout<<endl;

cout<<"Printing InOder : " ;
inOrderTraversal(root);
cout<<endl;

cout<<"Printing postOder : " ;
postOrderTraversal(root);
cout<<endl;

cout<<"Printing LevelOder : " ;
levelOrderTraversal(root);
cout<<endl;

}