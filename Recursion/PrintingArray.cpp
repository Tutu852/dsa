#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

void printArray(int arr[] , int size,int index){
    //base case 
    if(index >= size){
        return ;
    }
    //processing
    cout<< arr[index] << " ";

    //recursive call
    printArray(arr,size,index+1);
}

bool searchArray(int arr[] , int size,int target,int index){
    //base case
    if(index >= size){
        return false;
    }
    if(arr[index] == target){
        return true;
    }
    //recursize call
    bool aagekaAns= searchArray(arr,size,target,index+1);
    return aagekaAns;
}

void findMin(int arr[] ,int size,int index , int &mini){
    //if we not pass by reference mini then it will give wrong ans because if we not send it then it will create as copy that why the actual mini will not give..when we give &mini then it will work on that array only
    //aagar hum kisi variable ko ya kisi data hum yahna pe with in a function me data mini pas karrahehne aagar hum ase kartehne then hume pass by reference karna hoga barna error ayega
    //base case
    if (index >= size)
    {
        return;
    }
    //processing 
    mini = min(mini,arr[index]);

    //recursive call
    findMin(arr ,size,index+1,mini);
    
}

void findeven(int arr[],int size,int index, vector<int>&ans){
     if (index >= size)
        {
            return;
        }
        if(arr[index] %2 ==  0 ){
            ans.push_back(arr[index]);
        }
        //recursive call
        findeven(arr,size,index+1,ans);
}

void doublearray(int arr[] ,int size,int index){
    if (index >= size)
        {
            return;
        }
    //processing
    for(int i=0;i<size;i++){
        arr[index] = arr[index]*2;
    }

    //recursive
    doublearray(arr,size,index+1);
}
int main(){
    int arr[] = {10,20,30,40,50};
    // int arr[] = {2,3,4,5,6};
    int size= 5;
    int index =0;
    vector<int>ans;
    int target =50;
    cout<< "target is :"<< searchArray(arr,size,target,index)<<endl;
    // int mini =INT_MAX;

    // findMin(arr,size,index,mini);

    // doublearray(arr,size,index);


    // cout<<"Minimum ans is "<<mini<<endl;

    printArray(arr,size,index);
    // findeven(arr,size,index,ans);
    //printing vector
    // for(int num:ans) {
    //    cout << num << " " ;
    // }
}