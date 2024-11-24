#include<iostream>
#include<queue>
using namespace std;


class Queue{
    public:
        int *arr;
        int size;
        int front;
        int rear;

//ctor
    Queue(int size){
        arr = new int[size];
        this->size = size;

        front = -1;
        rear = -1;

        for(int i=0;i<size;i++){
            arr[i] = 0;
        }
    }

    // push 

    void push(int val){
        //check full
        if(rear == size -1){
            cout<<"Queue Overflow"<<endl;
            return;
        }else if(front == -1 && rear == -1){
            // not full 
            front++;
            rear++;
            arr[rear] = val;

        }else{
            //normal case
            rear++;
            arr[rear] = val;
        }
    }

    void pop(){
        //underflow

        if(front == -1 && rear == -1){
            cout<<"Queue Underflow" << endl;
            return;
        }
        else if(front == rear){
            //empty case ->single element
            arr[front] = -1;
            front = -1;
            rear = -1;
        }else{
            //normal case
            arr[front] = -1;
            front++;
        }
    }

    bool isEmpty(){
        if(front == -1 && rear == -1){
            return true;
        }else{
            return false;
        }
    }

    int getSize(){
        if(front == -1 && rear == -1){
            return 0;
        }else{

        return rear-front+1;
        }
    }

    int getFront(){
        if(front == -1){
            cout<<"NO element in queue, cantnot give front element" <<endl;   
        }else{
            return arr[front];
        }
    }

    void print(){
        cout<<"Print Queue : " ;
        for(int i = 0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

   
};


int main(){
 //creation
        Queue q(5);
        q.print();

        q.push(10);
        q.print();
        q.push(20);
        q.print();
        q.push(30);
        q.print();
        q.push(40);
        q.print();
        q.push(50);
        q.print();
        
        cout<< "Size of queue : " << q.getSize() <<endl;

        q.pop();
        q.print();

        cout<<"Size of queue " << q.getSize()<<endl;
        cout<<"Queue is empty or not : " <<q.isEmpty() <<endl;

        q.pop(); 
        q.pop(); 
        q.pop(); 
        q.pop();
        cout<< q.getFront() <<endl;
        q.pop();q.print(); 

        cout<<"Size of queue " << q.getSize()<<endl;

    return 0;
}