#include<iostream>
using namespace std;

void findmissing(int *a,int n){
    for(int i=0;i<n;i++){
        //index koi -ve na ho
        int index =abs(a[i]);
        
        // mera index 0 se start hota he but number 1 se so to make it same i am doing index -1 
        if(a[index - 1] > 0){
            //jo index aya us index me vis  mark kardo
            a[index - 1] *= -1;
        }
    }

    //all positive indexes are missing
    for(int i=0;i<n;i++){
        if(a[i] > 0){
            cout<< i+1 <<" " ;
        }
    }
}


int main(){
 int n;
 int a[] = {1,3,5,3,5};
 n= sizeof(a)/sizeof(int);
 findmissing(a,n);
 return 0;   
}