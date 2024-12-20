#include<iostream>
using namespace std;

class info{
    public:
    int maxVal;
    bool isHeap;

   info(int value, bool data){
    this->maxVal = value;
    this->isHeap = data;
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
    if(root->data > leftAns.maxVal && root->data >rightAns.maxVal && lwf)

};

int main(){

}