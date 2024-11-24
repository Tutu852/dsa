#include<iostream>
#include<string.h>
using namespace std;

int findLength (char ch[] ,int size){
    int length =0;

    for(int i = 0;i<size ;i++){
        if(ch[i] == '\0'){
            break;
        }else{
            length ++;
        }
    }
    return length;
}

bool isPalindrom (char ch[] , int n ){
    int i = 0;
    int j =n-1;

    while (i<=j){
        if(ch[i] == ch[j]){
            i++;
            j--;
        }
        else{
            return false;

        }
    }
    return true;
}


int main(){
    char ch[100];

    cin.getline(ch,100);

    int len = findLength(ch ,100);

    bool checkPalindrom =isPalindrom(ch, len);

    if(checkPalindrom){
         cout<<"valid palindrom" <<endl;
    }else{
        cout<<"Invalid Palindrom" <<endl;
    }
    
}