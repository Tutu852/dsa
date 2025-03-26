#include<iostream>
#include<vector>
using namespace std;

int solveUsingRec(int capacity,int wt[],int profit[],int index,int n){
    //base case
    //here in tabulation some problem will occure
    if(index>=n){
        return 0;
    }
    //thi is another base case
    // if(index == n-1){
    //     //single element he then profit[index] profit ko store karlo
    //     if(wt[index] <= capacity){
    //         return profit[index];
    //     }else{
    //         return 0;
    //     }
    // }

    // inc /exc 
    int include  =0;
    //agar current item ka weight capacity se kam he
    if(wt[index]<=capacity){
        include = profit[index] + solveUsingRec(capacity-wt[index],wt,profit,index+1,n);
    }
    //exclude
    int exclude = 0 + solveUsingRec(capacity,wt,profit,index+1,n);
    int ans = max(include,exclude);
    return ans;
}

// void printdparray(vector<vector<int>>&dp){
//     for(int i=0;i<dp.size();i++){
//         for(int j=0;j<dp[0].size();j++){
//             cout<<dp[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }

int solveUsingMem(int capacity,int wt[],int profit[],int index,int n,vector<vector<int>>&dp){
  
    if(index>=n){
        return 0;
    }

    //arlready exist wala case
    if(dp[capacity][index] != -1){
        return dp[capacity][index];
    }

    // inc /exc 
    int include  =0;
    //agar current item ka weight capacity se kam he
    if(wt[index]<=capacity){
        include = profit[index] + solveUsingMem(capacity-wt[index],wt,profit,index+1,n,dp);
    }
    //exclude
    int exclude = 0 + solveUsingMem(capacity,wt,profit,index+1,n,dp);
    //because yehi do value change hua a so in dp i pass these two
    dp[capacity][index] = max(include,exclude);
    // printdparray(dp);
    return dp[capacity][index];
}
int solveUsingTab(int capacity,int wt[],int profit[],int index,int n){

    //create dp array
    vector<vector<int>>dp(capacity+1, vector<int>(n + 1, -1));
//     //base case
//    for(int row=0;row<=capacity;row++){
//     dp[row][n] = 0;
//    }
   //here i =capacity and j  = index;
   //in mem we move towards capacity to 0 but here we will move from 0 to capacity
   for(int i=0;i<=capacity;i++){
    for(int j=n-1;j>=0;j--){
        //arlready exist wala case
        if(dp[i][j] != -1){
            continue;
            }     
    // inc /exc 
    int include  =0;
    //agar current item ka weight capacity se kam he
    if(wt[j]<=i){
        include = profit[j] + dp[i-wt[j]][j+1];
    }
    //exclude
    int exclude = 0 + dp[i][j+1];
    //because yehi do value change hua a so in dp i pass these two
    dp[i][j] = max(include,exclude);

    }
   }
   return dp[capacity][0];
}
int solveUsingTabSO(int capacity,int wt[],int profit[],int index,int n){

    //create dp array
    vector<int>next(capacity +1,0);
    vector<int>curr(capacity+1,-1);

  
   //here i =capacity and j  = index;
   //in mem we move towards capacity to 0 but here we will move from 0 to capacity
   for(int j=n-1;j>=0;j--){
   for(int i=0;i<=capacity;i++){
       
    // inc /exc 
    int include  =0;
    //agar current item ka weight capacity se kam he
    if(wt[j]<=i){
        include = profit[j] + next[i-wt[j]];
    }
    //exclude
    int exclude = 0 + next[i];
    //because yehi do value change hua a so in dp i pass these two
    curr[i] = max(include,exclude);

    }
    next = curr;
   }
   return curr[capacity];
}

int main(){
    int capacity =50;
    int wt[] = {10,20,30};
    int profit[] = {60,100,120};
    int index = 0;
    int n = 3;


    //creta an 2D array
    vector<vector<int>>dp(capacity+1, vector<int>(n + 1, -1));

    int ans = solveUsingTabSO(capacity,wt,profit,index,n);
    cout<<"max Profit: " <<ans<<endl;
    //in tabulation its better to remove index it is good 
    // int ans = solveUsingTab(capacity,wt,profit,index,n);
    // cout<<"max Profit: " <<ans<<endl;
    // int ans = solveUsingMem(capacity,wt,profit,index,n,dp);
    // cout<<"max Profit: " <<ans<<endl;
    // int ans = solveUsingRec(capacity,wt,profit,index,n);
    // cout<<"max Profit: " <<ans<<endl;
}