#include<iostream>

#include<limits.h>
using namespace std;

class info{
    public:
    int maxVal;
    bool isHeap;
    int data;
    info* left;
    info* right;

    info() {
        maxVal = INT_MIN; // Initialize maxVal to the smallest integer
        isHeap = true;    // Default value for isHeap
    }

   info(int value, bool data){
    this->maxVal = value;
    this->isHeap = data;
    this->data = value;
    this->left = NULL;
    this->right = NULL;
   }
};

info checkMaxheap(info* root){
    //base case
    if(root == NULL){
        info temp;
        temp.maxVal =INT_MIN;
        temp.isHeap =true;
        return temp;
    }
    //leaf node wala case
    if(root->left == NULL && root->right == NULL){
        info temp;
        temp.maxVal = root->data;
        temp.isHeap = true;
        return temp;
    }
    info leftAns = checkMaxheap(root->left);
    info rightAns = checkMaxheap(root->right);
    //1 case mujhe solve karna he
    if(root->data > leftAns.maxVal && root->data >rightAns.maxVal && leftAns.isHeap && rightAns.isHeap){
        info ans;
        ans.maxVal = root->data;
        ans.isHeap = true;
        return ans;
    }else{
        info ans;
        ans.maxVal =max(root->data , max(leftAns.maxVal,rightAns.maxVal));
        ans.isHeap = false;
        return ans;
    }
};

int main(){

}