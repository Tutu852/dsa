#include<iostream>
#include<queue>
using namespace std;

class Heap{
    public:
    int *arr;
    int size;
    int capacity;

    Heap(int capacity){
        //creating a dynamic array
        this->arr = new int[capacity];
        this->capacity = capacity;
        this->size = 0;
        arr[0] = 0;
    }
    void insert(int val){
        if(size == capacity){
            cout<<"Heap Overflow"<<endl;
        }
        //size increase kar jaege
        size++;
        int index = size; //size will pointed where the new element inserted
        arr[index] = val;

        //jab element ab uss ke original position pe ata he use heapification boltehne
        //take the val to its correct position

        while(index > 1){
            //sahi jagah pe lene keliye uska parentIndex ko check karna he pehele 
            int parentIndex = index / 2;
            if(arr[index] > arr[parentIndex]){
                //swap
                swap(arr[index],arr[parentIndex]);
                index = parentIndex;
            }else{
                break;
            }
        }
    }

    void printHeap(){
    for(int i = 0 ;i<=size;i++){
        cout<<arr[i]<<" ";
    }
}
//delete hamesha root node se hota he 
int deleteFromHeap(){
    //root node store karliya
    int answer =arr[1];
    //replacement
    //size wale ko store karo
    arr[1] = arr[size];
    // last element ko delete uski original position se
    size--;

    int index = 1;

    while(index < size){
        int leftIndex = 2 *index;
        int rightIndex = 2 * index +1;
        //findout karna he sabsebada koun
        int largestKaIndex = index;

        //check left child
        // mene yahna pe galti ki thi arr[index] lia tha but mere ko pura tino se compare karwana na left right and largetstIndex 
        if(leftIndex <= size && arr[largestKaIndex] < arr[leftIndex]){
        //agar left bala element largestkaindex se bada he the leftindex ko bada mark karo
            largestKaIndex = leftIndex;
        }
        if(rightIndex <= size && arr[largestKaIndex] <arr[rightIndex]){
            largestKaIndex = rightIndex;
        }   
        //no change happen
        if(index == largestKaIndex){
            break;
        }
        else{
            swap(arr[index],arr[largestKaIndex]);
            index = largestKaIndex;
        }
    }
    return answer;
}

};

void heapify(int *arr ,int n,int index){
    int largestKaIndex = index;
    int leftIndex = 2 * index;
    int rightIndex = 2 * index + 1;

    //teno me se max lao
    if(leftIndex <= n && arr[leftIndex] > arr[largestKaIndex]){
        largestKaIndex = leftIndex;
    }
    if(rightIndex <= n && arr[rightIndex] > arr[largestKaIndex]){
        largestKaIndex = rightIndex;
    }
    //after these 2 condition largestKaIndex will be pointing towards largest element among 3
    if(index != largestKaIndex){
        swap(arr[index],arr[largestKaIndex]);
        //ab rec sambal lega
        index = largestKaIndex;
        heapify(arr,n,index);
    }
}



void buildHeap(int arr[],int n){
    for(int index = n/2 ; index > 0 ; index--){
        heapify(arr,n,index);
    }
}

void heapSort(int arr[],int n){
    while(n!=1){
        swap(arr[1],arr[n]);
        n--;
        heapify(arr,n,1);
    }
}

int getKthSmallestElement(int arr[] ,int n, int  k){
    priority_queue<int>pq;

    //for k element ko process karo
    for(int i=0;i<k;i++){
        int element = arr[i];
        pq.push(element);
    }

    //remaining element ko tabhi insert karenge ab vo root se chotte honhne
    for(int i=k;i<n;i++){
        int element = arr[i];
        if(element < pq.top()){
            pq.pop();
            pq.push(element);
        }
    }
    int ans = pq.top();
    return ans;
}

int getKthGreatestElement(int arr[],int n,int k)
{
    priority_queue<int,vector<int>,greater<int>>pq;

    //for k element ko process karo
    for(int i=0;i<k;i++){
        int element = arr[i];
        pq.push(element);
    }

    //remaining element ko tabhi insert karenge ab vo root se chtte honhne
    for(int i=k;i<n;i++){
        int element = arr[i];
        if(element > pq.top()){
            pq.pop();
            pq.push(element);
        }
    }
    int ans = pq.top();
    return ans;
}



int main(){
    int arr[] = {3,5,4,6,9,8,7};
    int n =7;
    int k = 3;
    cout<<"4th smallest number is: " << getKthSmallestElement(arr,n,k) <<endl;
    cout<<"4th smallest number is: " << getKthGreatestElement(arr,n,k) <<endl;

    //on the 0th index i put -1 because i need to start from 1 th index so i put -1 in 0th index
    // int arr[] = {-1,5, 10, 15,20, 25, 12};
    // int n=6;
    // buildHeap(arr,n);
    // cout<<"Printing heap : "<<endl;
    // for(int i=1;i<=6;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // heapSort(arr,n);
    //     cout<<"Printing heap : "<<endl;
    // for(int i=1;i<=6;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // Heap h(20);

    // h.insert(10);
    // h.insert(20);
    // h.insert(5);
    // h.insert(11);
    // h.insert(6);

    // cout<<"printing the content of heap:  " <<endl;
    // h.printHeap();
    // int ans  = h.deleteFromHeap();
    // cout<<"Answer : "<<ans<<endl;

    // cout<<"printing the content of heap:  " <<endl;
    // h.printHeap();
    
    
}