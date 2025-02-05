#include<iostream>
// #include<map>
#include<unordered_map>
using namespace std;

void countCharacters(unordered_map<char,int> &mapping,string str){
    for(int i=0;i<str.length();i++){
        char  ch = str[i];
        mapping[ch]++;
    }
}



int main(){
    string str = "lovebabbar";
    //this ordered_map can help to give me in sorted order
    // map<char,int> mapping;

    unordered_map<char,int> mapping;
    countCharacters(mapping,str);

    for(auto i : mapping){
        cout<<i.first << "->" << i.second <<endl;
    }
}