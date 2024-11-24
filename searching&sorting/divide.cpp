#include<iostream>
using namespace std;

int getQuotient (int divisor ,int dividend){
    int s=0;
    int e=dividend;

    int mid = s+(e-s)/2;
    int ans = -1;


    while(s<e){
        if(mid * divisor == dividend){
            return mid;
        }
        if(mid * divisor < dividend){
            ans= mid;
            s = mid+1;
        }else{
            e= mid-1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}


int main(){
    int divisor = 7;
    int dividend = 29;
    int ans = getQuotient(abs(divisor),abs(dividend));
    //now we need to decide k sign konsa lagaya +ve ya -ve
    if((divisor > 0 && dividend <0) || (divisor > 0 && dividend <0)){
        ans = 0 -ans;
    }
    cout<<"Final ans is: "<< ans <<endl;
}