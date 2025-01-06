#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        this->data =value;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* insertIntoBST(Node* root,int data){
    if(root==NULL){
        root = new Node(data);
        return root;
    }
    //its not the first node
    if(data>root->data){
        root->right = insertIntoBST(root->right,data);
    }else{
        root->left = insertIntoBST(root->left,data);
    }
    return root;
}
void createBst(Node* & root){
    // cout<<"Enter data"<<endl;
    int data;
    cin>>data;


    while(data != -1){
       root= insertIntoBST(root,data);
    //    cout<<"Enter data: "<<endl;
        cin>>data;
    }
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
//this code is for CBT + BST -convert in valid Heap

void storeInorderTraversal(Node* root,vector<int>&in){

    if(root == NULL){
        return ;
    }
    // LNR
    storeInorderTraversal(root->left,in);
    in.push_back(root->data);
    storeInorderTraversal(root->right,in);

};
//mene yahna galti kia tha & wala .i need this because when i replace it's most
void replaceUsingPostOrder(Node*root,vector<int>in,int &index){
    if(root == NULL){
        return ;
    }
    //LRN
    replaceUsingPostOrder(root->left,in,index);
    replaceUsingPostOrder(root->right,in,index);
    //instade of printing the element i replace this value 
    root->data = in[index];
    index++;
}

Node* convertBSTIntoMaxheap(Node* root){
    //1step :- store inorder
    vector<int> inorder;
    storeInorderTraversal(root,inorder);

    //2nd 
    //replace the node values with the sorted inorder values,using the postorder treversal
    int index = 0;
    replaceUsingPostOrder(root,inorder,index);
    return root;
}

int main(){
    Node* root =NULL;
    createBst(root);
    cout<<"print in BST: "<<endl;

    levelOrderTraversal(root);
    cout<<endl;
    cout<<endl <<"Converting into Heap "<<endl;

    root =convertBSTIntoMaxheap(root);
    cout<<"Printing the heap "<<endl;
    levelOrderTraversal(root);
}