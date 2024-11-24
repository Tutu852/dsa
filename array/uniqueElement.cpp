#include<iostream>
using namespace std;

int getUnique(int arr[],int n){
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = ans ^ arr[i];
    }
    return ans;
}

void printPairs(int arr[] , int size){
    for(int i=0; i <size;i++){
        for(int j=0;j<size;j++){
            cout<<arr[i] << ", " << arr[j] << endl;
        }
    }
}

// void sortZeroOne(int arr[] ,int n){
//     int zeroCount = 0;
//     int oneCount = 0;
//     //stepA : count 0 and  1
//     for(int i =0; i<n ; i++){
//         if(arr[i]  == 0){
//             zeroCount++;
//         }
//         if(arr[i] == 1){
//             oneCount++;
//         }
//     }

//     //Step - B : place all zeros first
//    int index = 0;
//    while(zeroCount --){
//     //zeroCount-- is for what ever the count of zero is till there we need to move.
//     arr[index]=0;
//     index++;
//    }
//    while (oneCount--)
//    {
//     arr[index] = 1;
//     index++;
//    }
   
// }

//pointer approach sort zero one

void sortZeroOne(int arr[],int n){
    int l=0;
    int h = n-1;

    while(l<h){
        if(arr[l] == 0){
            l++;
        }
        if(arr[h] == 1){
            h--;
        }     
        swap(arr[l],arr[h]);
        //both swap and this code is same
        arr[l] = 0;
        arr[h] = 1;
        l++;
        h--;
    }
}

int main(){

    int arr[] ={0,1,0,1,0,1,1,1,1,0,0,0,0,0};
    int n =14;

    sortZeroOne(arr,n);

    //printing the array
    for(int i = 0; i<n ; i++){
        cout<<arr[i] << " ";
    }

    // int arr[] ={10,20,30};
    // int size= 3;

    // printPairs(arr,size);

    //  int arr[] = {2,10,11,10,2,13,15,13,15};
    //  int n = 9;

    //  int finalAns = getUnique(arr , n);
    //  cout<<"Final ans is :" << finalAns <<endl;
    return 0;
}