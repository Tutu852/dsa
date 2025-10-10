#include<iostream>
using namespace std;


int main(){
    // // Square
    // int n;
    // cin>>n;
    // for(int row=0;row<n;row++){
    //     for(int col=0;col<n;col++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }


    // //Hollow square
    // int n;
    // cin>>n;

    // for(int row=0;row<n;row++){
    //     for(int col=0;col<n;col++){
    //         if(row == 0 || row == n-1 ||col==0 || col == n-1){
    //             cout<<"*";
    //         }else{
    //             cout<<" ";
    //         }
    //     }
    //     cout<<endl;
    // }

    //hollow inverveted 

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 || j==0 || j== n -i-1){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}
