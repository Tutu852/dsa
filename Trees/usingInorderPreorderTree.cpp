#include<iostream>
#include<queue>
#include<map>
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

    int searchInorder(int inOrder[],int size,int target){
        for(int i=0;i<size;i++){
            if(inOrder[i] == target){
                return i;
            }
        }
        return -1;
    } 

void createMapping(int inOrder[],int size,map<int,int>&valueToIndexMap){
    //har ek element ke liye index create karahe
    for(int i = 0;i<size;i++){
        int element = inOrder[i];
        int index = i;
        valueToIndexMap[element] = index;

    }
}

Node* constructTreeFromPreAndInorderTraversal(map<int,int>&valueToIndexMap,int preOrder[],int inOrder[],int &preIndex,int inOrderStart,int inOrderEnd,int size){
    //base case
    
    if(preIndex >=size || inOrderStart>inOrderEnd){
        return NULL;
    }

    //1 case main solve krta hu
    //mujhe preindex ko byReference pass karna bhul gaya tha
    int element = preOrder[preIndex];
    preIndex++;
    Node* root = new Node(element);
    //element search krna  padega inOrder me
    // int position = searchInorder(inOrder,size,element);
    int position = valueToIndexMap[element];
    //baaki recursion sambhal lega

    root->left = constructTreeFromPreAndInorderTraversal(valueToIndexMap,preOrder,inOrder,preIndex,inOrderStart,position-1,size);
    root->right = constructTreeFromPreAndInorderTraversal(valueToIndexMap,preOrder,inOrder,preIndex,position+1,inOrderEnd,size);

    return root;
};


Node* constructTreeFromPostAndInorderTraversal(map<int,int>&valueToIndexMap,int postOrder[],int inOrder[],int &postIndex,int inOrderStart,int inOrderEnd,int size){
    //base case
    
    if(postIndex < 0 || inOrderStart>inOrderEnd){
        return NULL;
    }

    //1 case main solve krta hu
    //mujhe preindex ko byReference pass karna bhul gaya tha
    int element = postOrder[postIndex];
    postIndex--;
    Node* root = new Node(element);
    //element search krna  padega inOrder me
    // int position = searchInorder(inOrder,size,element);
    int position = valueToIndexMap[element];
    //baaki recursion sambhal lega
    //right ki order 1st lagega
    root->right = constructTreeFromPostAndInorderTraversal(valueToIndexMap,postOrder,inOrder,postIndex,position+1,inOrderEnd,size);
    root->left = constructTreeFromPostAndInorderTraversal(valueToIndexMap,postOrder,inOrder,postIndex,inOrderStart,position-1,size);

    return root;
};




int main(){

// int inOrder[] = {10,8,6,2,4,12};
// int preOder[] = {2,8,10,6,4,12};
// int size = 6;
// int preOrderIndex = 0;
// int inOrderStart = 0;
// int inOderEnd = 5;

// map<int,int>valueToIndexMap;
// createMapping(inOrder,size,valueToIndexMap);

// Node* root = constructTreeFromPreAndInorderTraversal(valueToIndexMap,preOder,inOrder,preOrderIndex,inOrderStart,inOderEnd,size);


//this is for post&inorder

int inOrder[] = {8,14,6,2,10,4};
int postOrder[] = {8,6,14,4,10,2};
int size = 6;
int postIndex = size-1;
int inOrderStart = 0;
int inOderEnd = size-1;

map<int,int>valueToIndexMap;
createMapping(inOrder,size,valueToIndexMap);

Node* root = constructTreeFromPostAndInorderTraversal(valueToIndexMap,postOrder,inOrder,postIndex,inOrderStart,inOderEnd,size);


cout<< "Printing the entire tree: "<<endl;
levelOrderTraversal(root);

    return 0;

}