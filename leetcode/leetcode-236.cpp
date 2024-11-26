class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
        return NULL;

        if(root == p)
        return p;

        if(root == q)
        return q;

        //ek case solve karo
        //left ka ans nikalo
        TreeNode* leftans = lowestCommonAncestor(root->left,p , q);
        TreeNode* rightans = lowestCommonAncestor(root->right,p , q);

        if(leftans  == NULL && rightans == NULL ){

        return NULL;
        }else if(leftans != NULL && rightans == NULL){
            return leftans;
        }else if(rightans != NULL && leftans == NULL){
            return rightans;
        }else{
            return root;
        }


    }
};