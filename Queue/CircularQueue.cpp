#include <iostream>
using namespace std;

class Cqueue {
public:
    int* arr;
    int size;
    int front;
    int rear;

    // Constructor with specified type for `size`
    Cqueue(int size) {
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;

         for(int i=0;i<size;i++){
            arr[i] = 0;
        }
    }

    // Destructor to free memory
    ~Cqueue() {
        delete[] arr;
    }




    void push(int val){
        //overflow
        if(front  == 0 && rear == size-1 ||  rear == front-1){
            cout<<"Overflow"<<endl;
        }
        //empty case->first element
        else if(front == -1 && rear ==-1){
            front++;
            rear++;
            arr[rear] = val;
        }
        //circular nature
        else if(rear == size-1 && front != 0){
            rear = 0 ; 
            arr[rear] = val;
        }
        //normal flow
        else{
            rear++;
            arr[rear] = val;
        }
    }

    void pop(){
        //underflow
        if(front == -1 && rear == -1){
            cout<<"Underflow" <<endl;
        }
        //empty case 
        else if(front  == rear){
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        // circular nature
        else if(front  == size - 1){
            arr[front] = -1;
            front = 0;
        }else{
        // normal flow 
            arr[front] = -1;
            front++;
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

int main() {
    Cqueue q(5); // Create a circular queue with size 5
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
    q.push(60);
    q.print();

    q.pop();
    q.pop();
    q.pop();
    q.print();

    q.push(100);
    q.print();
    q.push(110);
    q.print();
    q.push(120);
    q.print();
    q.push(130);
    q.print();
    return 0;
}
