#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){
        // cout<<"default constructor" <<endl;
        this->next = NULL;
    }
    Node(int _data){ 
        // cout<<"Parameterised constructor "<<endl;
        this->data = _data;
        this->next = NULL;
    }
    ~Node(){
        cout<<"Destructor called for: "<<endl;
    }

};

void printLL(Node* head){
    //temp ko head pe place kia he
    Node* temp = head;

    while(temp!=NULL){
        cout<<temp->data << "->";
        temp = temp->next; 
    }
    cout<<endl;
};

///print lenght

 int printLength(Node* head){
    Node* temp = head;
    int len =0;

    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
 }

 //insert in head
 void insertAtHead(Node* &head,Node* &tail,int data){
    if(head ==NULL){
        //empty LL
        //step1 : create new node
        Node* newNode = new Node(data);
        // step2 update new node
        head =newNode;
        tail =newNode;

    }else{

    Node* newNode = new Node(data);
    //attach new node to head node
    newNode->next = head;
    // update head 
    head = newNode;
    }
 };

 void insertAttail(Node* &head , Node*&tail , int data){
    if (head == NULL){
        //empty LL
        //create karo node ko
        Node* newNode = new Node(data);
        //step-2
        // single node h entire list me 
        //that's why head and tail ko isper point karwaya
        head = newNode;
        tail = newNode;

    }else{
        //non empty LL
        //step:1 create new Node

        Node* newNode = new Node(data);

        //step:-2 tail node attach karo newnode se
        tail->next = newNode;
        //step:-3
        tail = newNode;
    }
 };


 void createTail (Node* &head , Node* &tail){
    Node *temp = head;

    while (temp -> next != NULL)
    {
        temp = temp->next;
    }
    //jab ye loop khatam hogya hoga
    //then aapka temp wala pointer
    // kahada hoga last nde pr 
    //tab tail = temp karke, tail ko last node pr le aao

    tail = temp;
    
 }


 void insetAtPosition(Node* &head ,Node* &tail ,int data, int position){
 
    int length = printLength(head);
   

    if(position == 1){
        insertAtHead(head ,tail, data);
    }else if(position > length +1){
        //yahna galat he length +1 hoga
        insertAttail(head,tail,data);
    }else{
        //insert at middle of linked list

        // step:1 create a new node 
        Node* newNode = new Node(data);
        //step:2 traverse prev //curr to position
        Node*prev = NULL;
        Node*curr = head;

        while(position != 1){
            prev = curr;
            curr = curr->next;
            position--;
        }
        //step: 3 attach prev to new Node
        prev -> next = newNode;
        newNode -> next = curr;
    }
 }

void deleteNode (Node* &head , Node* &tail, int position){
    //empty list

    if(head == NULL){
        cout<<"Can't delete because LL is empty" <<endl;
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
    //delte from head
    if(position == 1){
        //first node ko delete kardo
        Node* temp =head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }else if(position == len){
        //last node ko delete kardo
        // find prev

        Node* prev =head;
        while(prev -> next != tail){
            prev = prev->next;
        }
        //prev node ka link null karo
        prev->next = NULL;
        //node delete kardo
        delete tail;
        //update tail
        tail = prev;
    }else{
        //middle node ko delete kardo

        //step:-1 set prev /curr pointer
        Node* prev = NULL;
        Node* curr =head;

        while(position != 1){
            position--;
            prev =curr;
            curr = curr->next;
        }

        //step-2 prev->next me curr ka next node add karo

        prev->next = curr->next;

        // step-3 node isolate karo
        curr->next = NULL;
        //step:-4 delete node
        delete curr;

    }
}

int main(){
    Node*head = NULL;
    Node*tail = NULL;

    insertAtHead(head,tail,10);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,40);
    insertAtHead(head,tail,50);
    printLL(head);

    
    // insetAtPosition(head ,tail,5,1);
    // insetAtPosition(head,tail,100,1);

    deleteNode(head,tail,3);
    printLL(head);






//     //creation of Node   
// //   Node a;
// // dynamic allocation
//   Node* first =new Node(10);  
//   Node* second =new Node(20);  
//   Node* third =new Node(30);  
//   Node* fourth =new Node(40);  
//   Node* fifth =new Node(50);  

//   first->next = second;
//   second->next = third;
//   third->next = fourth;
//   fourth->next = fifth;

//   Node* tail = fifth;

//   Node* head = first;
//   cout<<"Printing the entire LL: "<<endl;
//   printLL(head);

//   //check length
//   cout<<"Length of the LL:" << printLength(head)<<  " " ;

//   //inset at head
//   insertAtHead(head,tail,100);
//   insertAttail(head,tail,500);
//   printLL(head);
}