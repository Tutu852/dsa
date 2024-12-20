#include<iostream>
#include<string.h>
using namespace std;

int findLength(char ch[],int size){
    //using while loop
    int len = 0;
    int index = 0;
    while(ch[index] != '\0'){
        len++;
    }
    return index;
    // int length = 0;
    // for(int i=0;i<size;i++){
    //     if(ch[i] ==  '\0'){
    //         break;
    //     }else{
    //         length++; 
    //     };
    // }
    // return length;
}

void  convertToUppercase(char ch[] ,int n){
    int index = 0;


     while(ch[index] != '\0'){
        char currentChar = ch[index];
        //check if lowercase then convert to upper case
        if( currentChar >= 'a' && currentChar <= 'z'){
            ch[index] = currentChar - 'a' + 'A';
        }
        index++;
     }
}

void convertUpperCase(char ch[],int n){ 
    int index = 0;
    while(ch[index] != '/0'){
        char currentChar = ch[index];
        if(currentChar >= 'a' && currentChar <= 'z'){
            ch[index] = currentChar - 'a' + 'A';
        }
        index++;
    }
}


int main(){

    // char ch[100];

    // // cin >> ch;
    // cin.getline(ch,100);
    // int len  =findLength(ch,100);
    // cout<< "length of string is " <<len <<endl;
    // cout<< "length of sring is "<< strlen(ch) <<endl;

    //convert to uppercase
    char ch[100];

    cin.getline(ch,100); 
    cout<<endl <<"before " <<ch <<endl;
    convertToUppercase(ch ,100);
    cout<<endl <<"after " <<ch <<endl;
}