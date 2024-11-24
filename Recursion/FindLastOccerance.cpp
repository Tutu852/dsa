#include<iostream>
using namespace std;

//i is for 0 index
void lastOccLTR(string &s,char x,int i ,int &ans){
    //base case
    if(i >= s.size()){
        return;
    }
    //prossing
    if(s[i] == x){
        ans=i;
    }
    lastOccLTR(s,x,i+1,ans);
}
void lastOccRTL(string &s,char x,int i ,int &ans){
    //base case
    if(i < 0){
        return;
    }
    //prossing
    if(s[i] == x){
        ans=i;
        return;
    }
    lastOccRTL(s,x,i-1,ans);
}


int main(){
    string s;
    cin>>s;
    char x;
    cin>>x;
    int ans = -1;
    lastOccLTR(s,x,0,ans);
    // lastOccRTL(s,x,s.size()-1,ans);
    cout<<ans<<endl;
}