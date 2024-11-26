class Solution {
public:
    void solve(TreeNode* root, int targetSum,vector<vector<int>>&ans,vector<int>temp,int sum){
        //base case
        if(root == NULL){
            return;
        }
        //1case solve karna he
        sum += root->val;
        temp.push_back(root->val);

        //extra case
        if(root->left == NULL && root->right == NULL){
            //verify
            if(sum == targetSum){
                ans.push_back(temp);
            }else{
                return;
            }
        }

    //recursion
    solve(root->left,targetSum, ans,temp,sum);
    solve(root->right,targetSum, ans,temp,sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        int sum = 0 ;
        solve(root,targetSum,ans,temp,sum);
        return ans;
    }
};