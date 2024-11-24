#include<iostream>
using namespace std;

void findSubsequences(string str,string output,int index){
    //base case
    if (index >= str.length()) {
        //ans jo he output string me build ho chuka he
        //print kardo
        //this -> mark is mark empty string also
        cout<<"->"<<output<<endl;
        return ;
    }
    char ch = str[index];

    // //exclude
    // findSubsequences(str,output,index+1);

    // //include
    // output.push_back(ch);
    // findSubsequences(str,output,index+1) ;

    //include
    output.push_back(ch);
    findSubsequences(str,output,index+1);

    //exclude
    output.pop_back();
    findSubsequences(str,output,index+1) ;



}

int main(){
    string str = "abc"; 
    string output=" ";
    int index= 0;
    findSubsequences(str,output,index);
    
    
}