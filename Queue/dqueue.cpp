#include<iostream>
#include<deque>
using namespace std;


//this is a right code but this is not a good code to write

class Deque{
    public:
    int *arr;
    int size;
    int front;
    int rear;


    Deque(int size){
        arr = new int[size];

        this->size = size;

        front = -1;
        rear = -1;
    }


    void pushBack(int val){
         //overflow;
            if(rear == size -1){
                cout<<"Overflow"<<endl;
            }else if(front == -1 && rear == -1){
                //empty case
                front++;
                rear++;
                arr[rear] = val;
            }else{
                //normal flow
                rear++;
                arr[rear] = val;
            }

    }

    void pushFront(int val){
        //overflow
        if(front == 0){
            cout<<"Overflow"<<endl;
        }else if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[front] = val;
        }else{
            front--;
            arr[front] =val;
        }
    }

    void popFront(){
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
    void popBack(){
        //underflow
        //single element
        //noramalflow

        if(front == -1 && rear == -1){
            cout<<"Underflow" <<endl;
        }else if(front == rear){
            arr[rear] = -1;
            front = -1;
            rear = -1;
        }else{
            arr[rear] = -1;
            rear --;
        }
    }
};


int main(){









    // deque<int>dq;


    // dq.push_back(10);
    // dq.push_front(20);

    // // dq.pop_back();
    // dq.pop_front();


    // cout<< dq.front()<<endl;
    // cout<<dq.back()<<endl;


    // cout<<dq.size() <<endl;

    return 0;
}