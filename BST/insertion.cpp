#include<iostream>
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
    cout<<"Enter data"<<endl;
    int data;
    cin>>data;


    while(data != -1){
       root= insertIntoBST(root,data);
       cout<<"Enter data: "<<endl;
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

void preOrder(Node*root){
    // NLR 
    if(root == NULL)
        return ;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
    
}
void inOrder(Node*root){
    // LNR 
    if(root == NULL)
        return ;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
    
}
void postOrder(Node*root){
    // LRN 
    if(root == NULL)
        return ;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
    
}
Node* minValue(Node* root){
    if(root == NULL){
        cout<<"NO MIN VALUE "<<endl;
        return NULL;
    }
    Node* temp =root;

    while(temp->left !=NULL){
        temp = temp->left;
    }
    return temp;
}
Node* maxValue(Node* root){
    if(root == NULL){
        cout<<"NO MAX VALUE "<<endl;
        return NULL;
    }
    Node* temp =root;

    while(temp->right !=NULL){
        temp = temp->right;
    }
    return temp;
}

bool searchInBST(Node* root,int target){
    if(root == NULL){
        return false;
    }

    //1case me solve karunga
    if(root->data == target){
        return true ;
    }

    //baaki sab recursion sambal lega
    bool leftAns = false;
    bool rightAns =false;
    if(target > root->data){
        rightAns=searchInBST(root->right,target);
    }else{
        leftAns = searchInBST(root->left,target);
    }
    return leftAns || rightAns;
}

Node* deleteFromBst(Node* root ,int target){
    //target ko dhundo
    //target to delete karo

    if(root == NULL){
        return NULL;
    }
    if(root->data == target){
        //ab delete karenge
        //4 cases
        //1case ->leaf node
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        else if(root->left !=NULL && root->right == NULL){
        //2case -> left non null and right null
            Node* childSubtree = root->left;
            delete root;
            return childSubtree;
        }
       else  if(root->left == NULL && root->right !=NULL){
        
        //3case left me NULL and right non NULL
            Node* childSubtree = root->right;
            delete root ;
            return childSubtree;
        }else{
            //a -> left subtree ki max value lap
            Node* maxNode = maxValue(root->left);
            //replacement
            root->data = maxNode->data;
            //maxNode ko delete karo
            root->left = deleteFromBst(root->left,maxNode->data);
        }
    }else if(root->data > target){
        //root->left iss liye add kia ki agar root node delete kardia then usko parent se od na he left se so left ko aya
        root->left= deleteFromBst(root->left,target);
    }else{
        //right me jao
        root->right= deleteFromBst(root->right,target);
    }
    return root;
}


Node* bstFromInorder(int inOrder[],int s,int e){
    //base case
    if(s>e){
        return NULL;
    }
    //1 case solve karo
    int mid  =s+(e-s)/2;
    int element = inOrder[mid];
    Node* root = new Node(element); 

    //bakki recursion
    root->left = bstFromInorder(inOrder,s,mid-1);
    root->right =bstFromInorder(inOrder,mid+1,e);

    return root;

}

//convert this BST into a sorted linked list
// vvvIMP question
void convertBSTtoDLL(Node*root , Node* &head){
    if(root == NULL){
        return;
    }
    // RNL 
    // R 
    convertBSTtoDLL(root->right,head);
    // N
    root->right = head;
    //i need this becauese if ll is null then it will give me erro so i need this

    if(head !=NULL){
    head->left =root;
    }
    head = root;
    // L 
    convertBSTtoDLL(root->left,head);
}

void printLinkedList(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->right;
    }
    cout<<endl;
}

Node* convertDLLtoBST(Node* &head,int n){
    //base case
    if(head == NULL || n<=0){
        return NULL;
    }
    // LNR 
    // L
    Node* leftsubtree = convertDLLtoBST(head,n/2);
    // N 
    Node* root = head;
    root->left = leftsubtree;

    //head update
    head = head->right;

    //R
    Node* rightsubtree = convertDLLtoBST(head,n-n/2-1);
    root->right=rightsubtree;
    return root;
};

int main(){
    Node* first =new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    first->right =second;
    second->left = first;
    second->right =third;
    third->left = second;

    Node* head = first;

    Node*root =convertDLLtoBST(head ,3);
    levelOrderTraversal(root);

    // int inOrder[] = {10,20,30,40,50,60,70};
    // int size = 7;
    // int start=0;
    // int end = size-1;
    // Node* root = bstFromInorder(inOrder,start,end);

    // levelOrderTraversal(root);

    // Node*head= NULL;
    // convertBSTtoDLL(root,head);
    // printLinkedList(head);

    // Node *root =NULL;
    // createBst(root);

    // levelOrderTraversal(root);

    // cout<<endl <<"INORDER: " ;
    // inOrder(root);
    // cout<<"PreOrder: " ;
    // preOrder(root);
    // cout<<"PostOrder : " ; 
    // postOrder(root);


    // cout<<endl;
    // Node* minNode = minValue(root);
    // if(minNode ==NULL){
    //     cout<< "There is no ndoe  in tree,so no min value" <<endl;
    // }else{
    //     cout<<"Min Value is: "<< minNode->data<<endl;
    // }
    // cout<<endl;
    // Node* maxNode = maxValue(root);
    // if(maxNode ==NULL){
    //     cout<< "There is no ndoe  in tree,so no max value" <<endl;
    // }else{
    //     cout<<"Max Value is: "<< maxNode->data<<endl;
    // }

    // int target;
    // cout<<"Enter the value to delete: "<<endl;
    // cin>>target;
    // while(target != -1){
    //     root = deleteFromBst(root,target);
    //     cout<<"Printing level order traversal: "<<endl;
    //     levelOrderTraversal(root);
    //     cout<<"Enter the value of target : "<<endl;
    //     cin>>target;
    // }

    // int t ;
    // cout<<"Enter the target "<<endl;
    // cin >>t;

    // while(t != -1){
    //     bool ans = searchInBST(root,t); 
    //     if(ans == true){
    //         cout<<"Target found"<<endl;
    //     }else{
    //         cout<<"Target not found"<<endl;
    //     }
    //     cout<<"Enter the target :"<<endl;
    //     cin >>t;
    // }
    return 0;
}