#include<iostream>
#include<stack>
using namespace std;

bool checkRedundant(string &str){
    stack<char>st;

    for(int i = 0;i<str.length();i++){
        char ch = str[i];

        if(ch == '(' || ch == '+' || ch == '-' ||ch == '*' || ch == '/'){
            st.push(ch);
        }else if(ch == ')'){
            int operaotrCount = 0;
            while(!st.empty() && st.top() != '('){
                char temp = st.top();
                if(temp == '+' || temp == '-' || temp == '*' || temp == '/'){
                    operaotrCount++;
                }
                st.pop();
            }
            //yahaper aap tabhi pahochoge jab
            //aapke stack k top pr ek opening bracket hoga
            st.pop();

            if(operaotrCount == 0){
                return true;
            }
        }
    }
    // aagr main yaha tak pohancha hu 
    //iska matlab k har ek bracket k pair k beech me
    //ek operator pkka mila hoga
    return false;
}


int main(){

string str = "((a+b)*(c+d))";
bool ans = checkRedundant(str);


if(ans == true){
    cout<<"Redundant Breackets Present "<<endl;
}else{
    cout<<"Redundant Brackets Not Present "<< endl;
}

    return 0;
}