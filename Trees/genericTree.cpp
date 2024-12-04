#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    int children_count;
    Node**childern;

    Node(int val){
        this->data = val;
        this->children_count = 0;
        this->childern = 0;
    }
};
Node* takeInput(){
    int data,count;
    cout<<"Enter root data: ";
    cin>>data;
    cout<<"Enter Children count for "<<data <<" node :";
    cin>>count;
    Node* root = new Node(data);
    root->children_count = count;
    root->childern  =new Node*[count]; //array to store links to children


    for(int i =0; i<count;i++){
        root->childern[i] =takeInput();
    }
    return root;
} ;

void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(0);


    //asli traversal start krete he
    while(!q.empty()){
        // if i take auto instde of Node* it will automatically combine with Node*
        Node* front = q.front();
        q.pop(); 

        if(front == NULL) {
            cout<<endl;
           if(!q.empty()){
             q.push(NULL);
           }
        }else{

        cout<<front->data <<" ";

            for(int i=0;i<front->children_count;i++){
                if(front->childern[i]){
                    q.push(front->childern[i]);
                }
            }
        }

    }
};


int main(){

    Node* root = takeInput();
    levelOrderTraversal(root);
    return 0;
}