#include<iostream>
#include<limits.h>
using namespace std;

void CountZeroOne( int arr[] ,int size){
    int zeroCount = 0;
    int oneCount = 0;

    for(int i=0;i<size;i++){
        if(arr[i] == 0){
            zeroCount++;
        }
        if(arr[i] == 1){
            oneCount++;
        }
    }
   cout<<"ZeroCount : " <<zeroCount << endl;
   cout<<"oneCount : " <<oneCount << endl;
}


int MinNumber(int arr[],int size){
    int minAns = INT_MAX;

    for(int i=0;i<size;i++){
        if(arr[i] < minAns){
            minAns = arr[i];
        }
    }
    return minAns;
}
int MaxNumber(int arr[],int size){
    int maxAns = INT_MIN;

    for(int i=0;i<size;i++){
        if(arr[i] > maxAns){
            maxAns = arr[i];
        }
    }
    return maxAns;
}


int main(){


// int arr[5];

// int n=5;

// for(int i=0; i<n ; i++){
//     cin>>arr[i] ;
// }

// cout<< "Printing after taking input" <<endl;
// //print the array
// for(int i =0 ;i<n ;i++){
//     cout<<arr[i]<< " ";
// }
// //doubleing up 

// for(int i=0 ;i<n;i++){
//     arr[i] = 2*arr[i];
// }
// //printing after double up

// cout<<"printing after duble up" <<endl;
// for(int i=0;i<n;i++){
//     cout<<arr[i]<<" ";
// }


// int arr[5] ={5,10,5,10,5};
// int n=5;
// int sum=0;
// for(int i=0;i<n;i++){
//     sum = sum+arr[i];
// }
// cout<< "printing sum :" << sum << endl;

// int arr[5] ={5,7,8,10,15};
// int n=5;
// int target = 10;
// bool flag = 0;
// for(int  i=0;i<n;i++){
//     if(arr[i] == target){
//         //found
//         flag = 1;
//         break;
//     }
// }
// if(flag == 1){
//     cout<<"target found" ;
// }else{
//     cout<<"target not found";
// }


// int arr[] = {0,0,0,1,1,0,1,0,1,0,1,0,1,1,1};

// int size = 15;
// CountZeroOne(arr,size); 

int arr[] = {4,5,3,7,5,3,8};
int size=7;

// int mininum = MinNumber(arr,size);
int maximum = MaxNumber(arr,size);

// cout<<"Minimum Number is: "<< mininum <<endl;
cout<<"Maximum Number is: "<< maximum <<endl;


}