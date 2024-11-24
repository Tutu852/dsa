#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>&v){
    for(int i=0 ; i< v.size();i++){
        cout<<v[i]<<" ";
    }
}

void bubbleSort(vector<int> &v){
    int n = v.size();
    for(int i=0;i< n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(v[j] > v[j+1]){
                 swap(v[j],v[j+1]);
            }
        }
    }
};

void seletionSort(vector<int> &v){
    int n =v.size();

    for(int i=0;i<n-1;i++){
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            if(v[j] < v[minIndex]){
                minIndex =j ;
            }
        };
        swap(v[i] ,v[minIndex]);
    }
}

void insertionSort(vector<int> & v){
    int n = v.size();
    //i =0 ko chhod dete hne
    for(int  i=1;i<n;i++){
        int key= v[i];
        int j= i-1;
        //move elements of arr[0...i-1]that are greater than 
        //key to one position ahead of there current position
        while(j >= 0 &&  v[j] > key){
            v[j+1] = v[j];
            j--;
        }
        v[j +1 ] = key;
    }
}
int main(){
    vector<int> v= {5,4,3,2,1};
    // bubbleSort(v);
    seletionSort(v);
    //insertionSort(v);
    print(v);


    return 0;
}