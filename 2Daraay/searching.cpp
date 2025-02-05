#include<iostream>
#include<limits.h>
using namespace std;

//print row wise
void printArray(int arr[][3],int row,int col){
    for(int i=0; i<row ;i++){
        for(int j=0;j<col ; j++){
            cout<<arr[i][j] << " ";
        }
         cout<<endl;
    }
}

void colwise(int arr[][3] , int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }
}

bool findTarget(int arr[][3], int row,int col,int target){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j] == target){
                return true;
            }
        }
    }
    return false;
}
int findMax(int arr[][3] ,int row,int col){
    int maxAns =INT_MIN;

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j] > maxAns){
                maxAns = arr[i][j];
            }
        }
    }
    return maxAns;
}

//finding min

int findMin(int arr[][3],int row,int col){
    int minAns = INT_MAX;

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j] < minAns){
                minAns = arr[i][j];
            }
        }

    }
    return minAns;
}

int rowWiseSum(int arr[][3],int row,int col){
    for(int i=0;i<row;i++){
    int sum = 0;
        for(int j=0;j<col;j++){
            sum+=arr[i][j];
        }

        cout<<sum<<endl;
    }
     
}
int colWiseSum(int arr[][3],int row,int col){
    for(int i=0;i<row;i++){
    int sum = 0;
        for(int j=0;j<col;j++){
            sum+=arr[j][i];
        }

        cout<<sum<<endl;
    }
     
}

//transpose;
void transpose(int arr[][3],int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<=i;j++){
            swap(arr[i][j] , arr[j][i]);
        }
    }
}

// void transpose(int arr[][3],int row,int col){
//     for(int i=0;i<row;i++){
//         for(int j=i;j<=col;j++){
//             swap(arr[i][j] , arr[j][i]);
//         }
//     }
// }
  


int main(){
    int arr[3][3] = {
        {10,20,30},
        {40,50,60},
        {70,80,90}
    };

    int row  =3;
    int col = 3;
    // int target = 100;

    // colwise(arr,row,col);
    // cout<<"found target or not: " << findTarget(arr,row,col,target)<<endl;
    // cout<<"printing the max No. : "<< findMax(arr,row,col)<<endl; 
    // cout<<"printing the min No. : "<< findMin(arr,row,col)<<endl; 
    //  rowWiseSum(arr,row,col); 
    //  colWiseSum(arr,row,col); 

     cout<< endl << "Printing before transpose" << endl;
  printArray(arr, row, col);

  cout<< endl  << "Doing transpose" << endl;
  transpose(arr, row,  col);

  cout<< endl  << "Printing after transpose" << endl;
  printArray(arr, row, col);

    return 0;
}