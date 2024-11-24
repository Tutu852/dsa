#include<iostream>
using namespace std;

void merge(int arr[],int s,int e){
    int mid = s+(e-s)/2;

    int lenLeft= mid -s +1;
    int lenRight = e-mid;

    //create left and right array using heap
    int *left=new int[lenLeft]; 
    int *right=new int[lenRight];

    //copy values from original array to left array
    int k = s;
    //k is starting index 
    //k-->starting index of left array values in orginal array
    for(int i=0;i<lenLeft;i++){
        left[i] = arr[k];
        k++;
    }

    //copy value from original array to right array
    k = mid+1;
     for(int i=0;i<lenRight;i++){
        right[i] = arr[k];
        k++;
    }

    //actual merge logic here
    //let array is already sorted
    //right array is already sorted
    int leftIndex = 0;
    int rightIndex = 0;
    //yaha mene chod dia tha
    // mainArrayIndex ka array send kia hua  he "s"
    int mainArrayIndex =s;

    while(leftIndex  < lenLeft && rightIndex < lenRight){
        if(left[leftIndex] < right[rightIndex]){
            arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }else{
             arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
    }
    //left array ka elemnt khatam hogaya par right aray ka element he
    while(rightIndex < lenRight){
          arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
    }
    //right array ka elemnt khatam hogaya par left aray ka element he
    while(leftIndex < lenLeft){
        // original Array add kardo
          arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
    }
    //delete the heap memory
    delete[] left;
    delete[] right;
}

void mergeSort(int arr[],int s , int e){
    //base case 
    if (s >= e){
        return;
    }
    //break
    int mid = s + (e-s)/2;
    // s-->mid left 
    // mid+1-->right 

    // recursion ko bulao and 
    // left and right ko sort kardo 
    // recursive call to left array 
    mergeSort(arr,s,mid);
    // recursive call to right array 
    mergeSort(arr,mid+1,e);

    //merge two sorted array

    merge(arr,s,e);
}

int main(){
    int arr[] = {2,1,6,9,4,5};
    int size = 6;
    int s=0;
    int e = size-1;
     cout<< "Before merge sort " << endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<< " ";
    }
    cout<<endl;

    mergeSort(arr,s,e);

    cout<< "After merge sort " << endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<< " ";
    }
    cout<<endl;
}