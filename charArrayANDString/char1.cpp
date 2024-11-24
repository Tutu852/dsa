#include<iostream>
using namespace std;


int main(){
    char ch[10];

    cin >> ch;
    cout<<"The output of the char is : "<<ch<<endl;

    for(int i=0;i<10;i++){
        cout<<"At Index " << i <<" " << ch[i] <<endl;
            }

    char temp = ch[6];
    int val = int(temp);

    cout<<"Printing integer value  :"<<val <<endl;
    // // for array
    // int arr[10];
    // for(int i=0;i<10;i++){
    //     cin>>arr[i];
    // }
    // // print 
    // for(int i=0;i<10;i++){
    //     cout<<arr[i];
    // }

}