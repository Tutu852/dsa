class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base cse
        if(root == NULL){
            return NULL;
        }
        //case-1 p and q both comes in left subtree of root node
        if(p->val < root->val && q->val < root->val){
            TreeNode* leftans = lowestCommonAncestor(root->left,p,q);
            return leftans;
        }
        //case-2 p and q both comes in right subtree of root node
        if(p->val > root->val && q->val > root->val){
            TreeNode* rightans = lowestCommonAncestor(root->right,p,q);
            return rightans;
        }
        //case-3 
        //p is in left subtree of root node && q is on right subtree of root node
        if(p->val < root->val && q->val > root->val){
            return root;
        } 
        //case-4
        //q id in left subtree of root node && p is on right subtree of root node
        if(q->val < root->val && p->val > root->val){
            return root;
        }
        return root;
    }
};