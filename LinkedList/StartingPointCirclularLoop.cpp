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


Node* getStartingPoint(Node* &head){
    //check for loop
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(fast == slow){
            break;
        }
    }

    //yahna tak pohncha iska matlab slow and fast meet kar chuke he
    slow = head;

    //slow and fast -> 1step se aage aage badhao
    while(fast != slow){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

Node* removeLoop(Node* head){
     Node* slow = head;
    Node* fast = head;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(fast == slow){
            break;
        }
    }
    //yahna tak pohncha iska matlab slow and fast meet kar chuke he
    slow = head;
    //slow and fast -> 1step se aage aage badhao
    while(fast != slow){
        slow = slow->next;
        fast = fast->next;
    }
    // starting point 
    Node* startPoint = slow;

    Node* temp =fast;

    while(temp->next != startPoint){
        temp= temp->next;
    }
    temp->next = NULL;
}

int main(){
    Node*head = NULL;
    Node*tail = NULL;

    insertAtHead(head,tail,20);
    insertAtHead(head,tail,50);
    insertAtHead(head,tail,60);
    
    insertAtHead(head,tail,90);
    insertAttail(head,tail,88);
    tail->next = head->next;
    cout<<getStartingPoint(head) -> data <<endl;

    removeLoop(head);
    printLL(head);

    cout<<endl;

    
   
}