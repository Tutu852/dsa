#include<iostream>
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
        int index = size;
        arr[index] = val;

        //take the val to its correct position

        while(index > 1){
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

int deleteFromHeap(){
    int answer =arr[1];
    //replacement
    arr[1] = arr[size];
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
            largestKaIndex = leftIndex;
        }
        if(rightIndex <= size && arr[largestKaIndex] <arr[rightIndex]){
            largestKaIndex = rightIndex;
        }

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
//tc

int main(){
    //on the 0th index i put -1 because i need to start from 1 th index so i put -1 in 0th index
    int arr[] = {-1,5, 10, 15,20, 25, 12};
    int n=6;
    buildHeap(arr,n);
    cout<<"Printing heap : "<<endl;
    for(int i=1;i<=6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapSort(arr,n);
        cout<<"Printing heap : "<<endl;
    for(int i=1;i<=6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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