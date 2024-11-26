class Solution {
public:
bool solve(TreeNode* root, int targetSum, int sum){
    //base case
    if(root == NULL){
        return false;
    }
    //sum ko har bar + karna he isilye mene yahna put kia sum ko
        sum += root->val;
    if(root->left == NULL && root->right == NULL){
        //i am currently standing on a leaf node
        //verify
        if(sum == targetSum)
            return true;
        else
            return false;
    }
    bool leftans = solve(root->left,targetSum,sum);
    bool rightans = solve(root->right,targetSum,sum);
    return leftans||rightans;
}
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool ans = solve(root, targetSum, sum);
        return ans;
    }
};