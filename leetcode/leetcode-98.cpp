class Solution {
public:

    bool solve(TreeNode* root ,long long int lowerBound , long long int upperBound){
        //base case
        if(root == NULL){
            return true;
        }

        bool cond1= (root->val > lowerBound);
        bool cond2= (root->val < upperBound);
        bool leftans = solve(root->left ,lowerBound,root->val);
        bool rightans = solve(root->right, root->val,upperBound);

        if(cond1 && cond2 && leftans && rightans)
            return true;
        else
            return false;
        
    } 

    bool isValidBST(TreeNode* root) {
        
        long long int lowerBound = -2147483657;
        long long int upperBound = 2147483657;

        bool ans = solve(root , lowerBound , upperBound);
        return ans;
    }
};