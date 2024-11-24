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
        this->left =NULL;
        this->right= NULL;
    };
};

Node* createTree(){
    cout<<"Enter the value of Node : "<<endl;

    int value;
    cin>>value;

    if(value == -1){
        return NULL;
    }

    // create Node 
    Node* root = new Node(value);
    cout<<"Entering in left of : " <<value<<endl;
    root->left = createTree();
    cout<<"Entering in right of : " <<value<<endl;
    root->right = createTree();

}

    void preOrder(Node* root){
        if(root == NULL)
            return;
        //N L R
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    
}
    void InOrder(Node* root){
        if(root == NULL)
            return;
        //L N R
        preOrder(root->left);
        cout<<root->data<<" ";
        preOrder(root->right);
    
}
    void postOrder(Node* root){
        if(root == NULL)
            return;
        //L R N
        preOrder(root->left);
        preOrder(root->right);
        cout<<root->data<<" ";
    
}


void levelOrderTraversal(Node* root){
    queue<Node*>q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }
}

void printLeftView(Node* root,int level,vector<int>&leftView){
    if(root == NULL){
        return;
    }
    if(level == leftView.size()){
        //iska matlab left view ki node milgayi h ,store karlo
        leftView.push_back(root->data);
    }
    printLeftView(root->left ,level+1,leftView);
    printLeftView(root->right ,level+1,leftView);
};

void printRightView(Node* root,int level,vector<int>&RightView){
    if(root == NULL){
        return;
    }
    if(level == RightView.size()){
        //iska matlab left view ki node milgayi h ,store karlo
        RightView.push_back(root->data);
    }
    printRightView(root->right ,level+1,RightView);
    printRightView(root->left ,level+1,RightView);
};


void printTopView(Node* root){
    map<int,int>hdToNodemap;
    // mene queue me harek dabe pe node kuan he use stroe kia hua tha and level store kia hua tha so pair leke kia
    //int for child mene jo insert kia uska level ka track rakhne keliye liya he
    queue<pair<Node*,int>>q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        //top node ko nikal dia
        pair<Node*,int> temp = q.front();
        q.pop();
        //1st wala  node nikaldia 
        Node* frontNode = temp.first; 
        int hd = temp.second;
        //if there is no entry for hd in map, then create a new entry
        if(hdToNodemap.find(hd) == hdToNodemap.end()){
            hdToNodemap[hd] = frontNode->data;
        }

        //child ko dekhna he
        if(frontNode->left != NULL){
            q.push(make_pair(frontNode->left,hd-1));
        }
        if(frontNode->right != NULL){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }
    cout<< " printing top view: "<<endl;
    for(auto it : hdToNodemap){
        cout<<it.second<<" ";
    }
};
void printBottomView(Node* root){
    map<int,int>hdToNodemap;
    // mene queue me harek dabe pe node kuan he use stroe kia hua tha and level store kia hua tha so pair leke kia
    //int for child mene jo insert kia uska level ka track rakhne keliye liya he
    queue<pair<Node*,int>>q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        //top node ko nikal dia
        pair<Node*,int> temp = q.front();
        q.pop();
        //1st wala  node nikaldia 
        Node* frontNode = temp.first; 
        int hd = temp.second;
        //if there is no entry for hd in map, then create a new entry
     
            hdToNodemap[hd] = frontNode->data;
        

        //child ko dekhna he
        if(frontNode->left != NULL){
            q.push(make_pair(frontNode->left,hd-1));
        }
        if(frontNode->right != NULL){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }
    cout<< " printing top view: "<<endl;
    for(auto it : hdToNodemap){
        cout<<it.second<<" ";
    }
};


void printLeftBoundary(Node* root){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        return;
    }
    // main condition 
    
    cout<<root->data<<" ";
    if(root->left != NULL){
        printLeftBoundary(root->left);
    }else{
        printLeftBoundary(root->right);
    }

}

void printLeafBoundary(Node* root){
    if(root == NULL){
    return;
    };
    if(root->left == NULL && root->right == NULL){
        cout<<root->data<<" ";
    }

    printLeafBoundary(root->left);
    printLeafBoundary(root->right);
}

void printRightBoundary(Node* root){
    if(root == NULL){
        return;
    }
     if(root->left == NULL && root->right == NULL){
        return;
    }
    // main condition 
    
    if(root->right != NULL){
        printLeftBoundary(root->right);
    }else{
        printLeftBoundary(root->left);
    }
    cout<<root->data<<" ";
}

void BoundaryTraversal(Node* root){
    if(root == NULL){
        return;
    }
    //root ko handle karliya
    cout<<root->data<<" ";
    //root ka left part ko handle karliya
    printLeftBoundary(root->left);
    //dono ko ek saath iss liye nehni kia ki single case pe do par print ho jata issliye leaf left and right ko aalg se handle kia
    
    //left part ke leaf node ko print karliya
    printLeafBoundary(root->left);
    //right part ke leaf node ko print karliya
    printLeafBoundary(root->right);
    // root ke right part ko handle karliya
    printRightBoundary(root->right);
 
}


int main(){
    Node* root = createTree();
    // 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1
    levelOrderTraversal(root) ;
    BoundaryTraversal(root);
    // printTopView(root);
    // printBottomView(root);
    // vector<int>leftView;
    // vector<int>RightView;
    // printLeftView(root,0,leftView);
    // printRightView(root,0,RightView);

    // cout<<"Printing Left View" <<endl;

    // for(int i=0;i<leftView.size();i++){
    //     cout<<leftView[i]<<" ";
    // }
    //     cout<<endl;
    // cout<<"Printing Right View" <<endl;
    // for(int i=0;i<RightView.size();i++){
    //     cout<<RightView[i]<<" ";
    // }
    return 0;
}