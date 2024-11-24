#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>&st ,int &element){
    //base case
    if(st.empty()){
        st.push(element);
        return;
    }
    //1case solve karo
    int temp = st.top();
    st.pop();

    //baki recursion
    insertAtBottom(st, element);

    //backtrack
    st.push(temp);
}

void reverseStackRec(stack<int> &st){
    //base case
    if(st.empty()){
        return;
    }

    //1 case main solve karega

    int temp = st.top();
    st.pop();


    //rec
    reverseStackRec(st);

    //backtrack

    insertAtBottom(st,temp);
}

void insertSorted(stack<int>&st , int element){
    //base case

    if(st.empty() || element  >st.top()){
        st.push(element);
        return;
    }

    //1case sambhalena he

    int temp = st.top();
    st.pop();

    //recursion sambhalega 
    insertSorted(st,element);

    //backtrack
    st.push(temp);
}

void sortedStack(stack<int> &st){
    //base cse
    if(st.empty()){
        return;
    }

    //1case solve kia

    int temp = st.top();
    st.pop();

    //recursion
    sortedStack(st);

    //backtracking
    insertSorted(st,temp);
}


int main(){

stack<int>st;

st.push(10);
st.push(20);
st.push(30);
// int element = 400;

// insertAtBottom(st,element);

// reverseStackRec(st);

// insertSorted(st,25);

sortedStack(st);

while(!st.empty()){
    cout<< st.top() << " ";
    st.pop();
}
}