#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextSmallestElement(int *arr , int size ,vector<int>&ans){
    stack<int>st;
    st.push(-1);

    for(int i=size-1 ; i >=0 ; i--){
        int curr = arr[i];
        //answer find karo curr k liye
         while(st.top() >= curr){
            st.pop();
         }

         ans[i] = st.top();
         st.push(curr);
    }
    return ans;
}

vector<int> prevSmallestElement(int *arr , int size ,vector<int>&ans){
    stack<int>st;
    st.push(-1);

    for(int i=0 ; i<size-1 ; i++){
        int curr = arr[i];
        //answer find karo curr k liye
         while(st.top() >= curr){
            st.pop();
         }
         ans[i] = st.top();
         st.push(curr);
    }
    return ans;
}


int main(){
    int arr[] = {8,4,6,2,3};
    int size  =5;

    vector<int>next(size);
    next = nextSmallestElement(arr,size,next);
    for(auto i :next){
        cout<<i << " ";
    }
    cout<<endl;


    vector<int>prev(size);
    prev = prevSmallestElement(arr,size,prev);
    for(auto i :prev){
        cout<<i << " ";
    }
    cout<<endl;
    return 0;
}