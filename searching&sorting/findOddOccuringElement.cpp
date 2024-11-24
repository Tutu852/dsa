#include<iostream>
using namespace std;


int findOddOccuringElement(int arr[] ,int n){
    int s=0;
    int e=n-1;
    int mid =s+(e-s)/2;


    while(s<=e){
        //single element
        if(s==e){
            return s;
        }
        //mid check ->even or odd
        //this (mid & 1) for find the odd element
        if(mid & 1){
            if(mid-1 >= 0 && arr[mid] == arr[mid-1]){
                //right ku jiba
                s= mid+1;
            }else{
                e=mid-1;
            }
        } else{
            // even
            if(mid+1 < n &&arr[mid] == arr[mid+1]){
                //right
                s=mid+2;
            }else{
            //ya to me right part par khada hnu 
            // ya to me ans pe khada hnu
            //that's why e= mid karra hu
            //kyoki e = mid-1; se ans  lost ho sakta he
            e=mid;
            }
        }
        mid = s +(e-s)/2;

    }
    return -1;
}


int main(){

    int arr[] = {10,10,2,2,3,3,2,5,5,6,6,7,7};
    int n= 13;

    int ansIndex= findOddOccuringElement(arr,n);

    cout<<"findOddOccuringElement: " <<arr[ansIndex] <<endl;
    return 0;
}