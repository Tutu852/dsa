#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int solveUsingRecursion(int n, int x, int y, int z,vector<int>&dp)
    {
        //base case
        if(n == 0)
            return 0;
        //when < 0 occure it will move to  -ve value thats why we have to maintion here INT_MIN because we need to take maximum
        if(n < 0)
            return INT_MIN;

        if(dp[n] != INT_MIN){
            return dp[n];
        }
            
        //maine x lenth ka 1 segment cut karliya bakisab recursion sambhal lega
        int opt1 = 1 + solveUsingRecursion(n-x, x,y,z);
        //maine y lenth ka 1 segment cut karliya bakisab recursion sambhal lega
        int opt2 = 1 + solveUsingRecursion(n-y, x,y,z);
        //maine z lenth ka 1 segment cut karliya bakisab recursion sambhal lega
        int opt3 = 1 + solveUsingRecursion(n-z, x,y,z);
        
        int dp[n] = max(opt1, max(opt2 , opt3));
        return dp[n];
    }

    int maximizeTheCuts(int n,int x, int y,int z){
        vector<int>dp(n+1,INT_MIN);
        int ans = solveUsingRecursion(n,x,y,z,dp);
        return ans;
    }
};