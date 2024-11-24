#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void print(vector<int> & v){
    for(int i=0;i<v.size();i++){
        cout<<v[i] <<" ";
    }
}

bool myComp(int &a ,int &b){
    // return a<b; //this will sort in increasing order
    return a > b ; //this will sort in decreasing order
}

int main(){
    vector<int> v = {44,55,22,11,33};

    // sort(v.begin() , v.end());
    //for decreasing order
    //this myComp is a comparator
    sort(v.begin() , v.end() ,myComp);
    print(v);
}