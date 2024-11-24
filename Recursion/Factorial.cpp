#include<iostream>
using namespace std;

int factorial(int n){
    //Base case
    if(n==1 || n==0)
        return 1;
 
    //recursive relation

    int recursiveans = factorial(n-1);
     int ans = n*recursiveans;
    return ans;

}

int counting(int n){
    //base case
    if(n==1)
        return 1;
    //recursive relation
     int ans = n+ counting(n-1);
     return ans;
}

//print 5 to 1

void print(int n){
    //base case
    if(n==1)
       { cout << 1 << " ";
        return;}
    //processing
    cout<<n << " ";
    //recursice Call
    print(n-1);
    
}

int pow(int n){
    if(n==0){
        return 1;
    }

    int ans = 2 * pow(n-1);
    return ans;

}


int main(){

    // cout << factorial(5) <<endl;
    // cout << counting(5) <<endl;
    print(5) ;
    // cout<< pow(10)<<endl;

    return 0;
}