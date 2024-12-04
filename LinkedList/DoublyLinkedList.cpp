#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(){
        this->prev = NULL;
        this->next =NULL;
    }
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};


void print (Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data <<" ";
        temp = temp->next;
    }
}
 

 int printLength( Node* &head){
    //i create another pointer in head
    Node* temp =head ; 

    int len = 0;

    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
 }

 void insertAtHead (Node* &head, Node* &tail ,int data){
    //LL is empty
    if(head == NULL){
         Node* newNode = new Node(data);
         head = newNode;
         tail = newNode;
    }else{
        Node* newNode = new Node(data);
        newNode->next = head;
        head-> prev = newNode;
        head = newNode;
    }

 }
 void insertAttail (Node* &head, Node* &tail ,int data){
    //LL is empty
    if(head == NULL){
         Node* newNode = new Node(data);
         head = newNode;
         tail = newNode;
    }else{
        Node* newNode = new Node(data);
        tail-> next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

 }
 void insertAtmiddle (Node* &head, Node* &tail ,int data,int position){
    //LL is empty
    if(head == NULL){
         Node* newNode = new Node(data);
         head = newNode;
         tail = newNode;
    }else{
        int len = printLength(head);
       if(position == 1){
        insertAtHead(head,tail,data);
       }else if(position == len +1){
        insertAttail(head,tail,data);
       }
       else{
        //insert in middle
        //step1:create node
        Node* newNode = new Node(data);
        //step-2 set prev and curr pointer
        Node* prevNode = NULL;
        
        Node* currNode = head;
        while(position != 1){
            position--;
            prevNode =currNode;
            currNode = currNode->next;
        }
        //step-3 pointer update kardo
        prevNode -> next = newNode;
        newNode ->prev = prevNode;
        newNode ->next = currNode;
        currNode->prev = newNode;
       }
    }

 }

 void deleteNode(Node* &head,Node* &tail, int position){
    if(head == NULL){
        //LL is empty
        cout<<"cant delete LL is empty "<<endl;
        return ;
    }
    //single element
    if(head == tail){
        Node* temp = head;
        delete temp;
        head = NULL;
        tail =NULL;
        return;
        
    }
    int len = printLength(head);
    if(position == 1){
        //delete from head 
        Node* temp = head;
        head = head->next;
        temp -> next = NULL;
        head -> prev = NULL;
        delete temp;
    }else if(position == len){
        //delete from tail
        Node* prevNode = tail -> prev;
        prevNode->next = NULL;
        tail->prev = NULL;
        delete tail;
        tail = prevNode;
    }else{
        //delte form middle
        //set1 : set prevNode/currNode/nextNode
        Node* prevNode = NULL;
        Node* currNode = head;
        while(position != 1){
            position--;
            prevNode = currNode;
            currNode = currNode->next;
        }
        Node* nextNode = currNode ->next;

        prevNode->next = nextNode;
        currNode->prev = NULL;
        currNode->next = NULL;
        nextNode->prev = prevNode;

        delete currNode;
        
    }
 }



int main(){

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head,tail,40);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,10);
    print(head);
    cout<<endl;
    // insertAtmiddle(head,tail,1000,2);
    // print(head);

    // insertAttail(head,tail,1000);
    // print(head);

    deleteNode(head,tail,4);
    print(head);
    
    return 0 ;

}