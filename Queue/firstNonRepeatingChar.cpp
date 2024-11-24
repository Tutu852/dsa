#include<iostream>
#include<queue>
using namespace std;


int main(){

    string str = "abab";
    queue<char>q;

    int freq[26] = {0};

    for(int i =0;i<str.length();i++){
        char ch = str[i];
        freq[ch - 'a']++;
        q.push(ch);
    }


    //answer find karo
    // check empty 1st 

    while(!q.empty()){
        char frontCharacter = q.front();

        if(freq[frontCharacter - 'a'] > 1){
            //yaani ye ans nehni he
            q.pop();
        }else { 
            // ans he 
            cout<<frontCharacter<< " ->";
            break;
        }
    }

    if(q.empty()){
        cout<<"#"<< "->";
    }

    return 0;
}