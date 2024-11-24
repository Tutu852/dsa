#include<iostream>
#include<vector>
using namespace std;

void printDigit(int num,vector<int>&ans){
    //base case
    if(num == 0){
        return;
    }
    //processing
    int digit =num %10;
    //update num
    num = num /10;

    //recursive call

    printDigit(num,ans);

    //processing

   ans.push_back(digit);
 }


int main(){
    int num =4217;
    vector<int>ans;
    printDigit(num,ans);

    for(int num :ans){
        cout<< num << endl; 
    }
}