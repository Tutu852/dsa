#include<iostream>
using namespace std;

int binarySearch(int arr[] ,int start,int end,int target){
    //base case
    if(start> end){
        return -1;
    }
    //processing 1 case khud solve karo 
    int mid = start + (end-start)/2;
    //baki recursion sambalega
    if(arr[mid] == target){
        return mid;
    }
    if(arr[mid] < target){
        //recursive solution
        binarySearch(arr,mid+1,end,target);
    }else{
        // left me jao
        binarySearch(arr,start,mid-1,target);
    }
}

void findSubSequence(string str,string output,int index){
    //base case
}



int main(){
    int arr[] = {10,20,30,40,50,60,70,80};
    int size= 8;
    int start = 0;
    int end = size-1;
    int target = 90;


    int foundIndex = binarySearch(arr,start,end,target);

    if(foundIndex != -1){
        cout<< " target found at "<<foundIndex<<endl;
    }else{
        cout<<"target not found " <<endl;
    }

} 