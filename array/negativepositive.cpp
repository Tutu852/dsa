#include<iostream>
using namespace std;

void shiftingNegativeInteger(int arr[] ,int size){
   
   int  j=0;

   for(int i=0;i<size;i++){
    if(arr[i]  < 0){
        swap(arr[i],arr[j]);
        j++;
    }
   }
}
 


int main(){
    int arr[] = {23,-7,12,-10,-1,40,60};
    int size = 7;

    shiftingNegativeInteger(arr,size);

    //print
    cout<< "Printing the array " << endl;
    for(int i = 0; i <size; i++){
        cout<<arr[i] << " ";
    }
}