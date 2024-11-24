#include<iostream>
#include<stack>
#include<queue>
using namespace std;


// void reverseQueue(queue<int>&q){

//     stack<int>s;
//     //one by one queue se element lo and stack me daaloz
//     while(!q.empty()){
//         int frontElement = q.front();
//         q.pop();

//         s.push(frontElement);
//     }

//     //one by one stack se lo and queue me push karo
//     while(!s.empty()){
//         int element = s.top();
//         s.pop();

//         q.push(element);
//     }
    
// };


void reverseQueue(queue<int>&q){
    //base case
    if(q.empty()){
        return;
    }
    int element = q.front();
    q.pop();


    reverseQueue(q);

    q.push(element);
}


void reverseFirstK(queue<int>&q,int k){
    stack<int>st;
    int n   = q.size();

    //if k elementhi nehni he
    if(k>n || k == 0){
        return;
    }
    //push first k element into stack
    for(int i=0;i<k;i++){
        int temp = q.front();
        q.pop();
        st.push(temp);
    }

    //push all k element into queue
    while(!st.empty()){
        int temp = st.top();
        st.pop();
        q.push(temp);
    }
    //pop and push first (n-k) elements into queue again
    for(int i=0;i<(n-k);i++){
        int temp = q.front();
        q.pop();

        q.push(temp);
    }
}
void Interleavefirstandsecond(queue<int>& first){
    queue<int>second;
    //push first half of first queue in second queue
    int size = first.size();
    for(int i=0;i<size/2;i++){
        int temp = first.front();
        first.pop();

        second.push(temp);
    }

    //merge both the halves
    //into the original queue - named as first
    for(int i=0;i<size/2;i++){
        int temp =second.front();
        second.pop();
        first.push(temp);

        temp = first.front();
        first.pop();
        first.push(temp);
    }
};

void printFirstNegetive(int *arr,int n,int k){
    deque<int>dq;

    //process first k element -first window
    for(int i=0;i<k;i++){
        int element = arr[i];
        if(element<0){
            dq.push_back(i);
        }
    }
    //process remaining window - >removal and additon
    for(int i=k;i<n;i++){
      
        //aage badhne se pehele purane window ka ans nikalo 
          if(dq.empty()){
            cout<<"0"<<endl;
            }else{
                cout<<arr[dq.front()] << " ";
            }
        

        // removal -> jo bhi index out of range he usko queue me se remove kardo
        if(i - dq.front() >= k){
            dq.pop_front();
        }


        //Addition
        if(arr[i] < 0){
            dq.push_back(i);
        }
    }
    // last wala window ka answer print kardo
    if(dq.empty()){
        cout<<"0"<<endl;
    }else{
        cout<<arr[dq.front()] << " ";
    }
}


int main(){

    int arr[] = {2,-5,4,-1,-2,0,5};


    int size = 7;
    int k = 3;
    printFirstNegetive(arr,size,k);


    // queue<int>q;
    // q.push(10);
    // q.push(20);
    // q.push(30);
    // q.push(40);
    // q.push(50);
    // q.push(60);
    // // q.push(70);

    // // reverseFirstK(q,4);
    
    // Interleavefirstandsecond(q);
    // // reverseQueue(q);

    // cout<< "Printing Queue: "<<endl;

    // while(!q.empty()){
    //     int element = q.front();
    //     q.pop();
    //     cout<< element << " ";
    // }
}