class Solution {
public:
    int kthSmallest(TreeNode* root, int &k) {
        //base case
        if(root == NULL){
            return -1;
        }
        //LNR
        //
        int leftans = kthSmallest(root->left,k);
        if(leftans != -1){
            return leftans;
        }
        //N
        k--;
        if(k == 0){
            return root->val;
        }
        //r
        int rightans = kthSmallest(root->right,k);
         
            return rightans;
    }
};