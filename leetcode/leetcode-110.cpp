// class Solution {
// public:
// int height(TreeNode* root){

//     // this approach contain n2 timespace complexity
    
//     if(root == NULL)
//     return 0;

//     int leftHeight = height(root->left);
//     int rightHeight = height(root->right);
//     int finalans = max(leftHeight,rightHeight) +1;
//     return finalans;
// }
//     bool isBalanced(TreeNode* root) {
//         if(root == NULL)
//         return true;

//         //currNode -solve
//         //ek case solve karo
//         int leftHeight = height(root->left);
//         int rightHeight = height(root->right);
//         int diff = abs(leftHeight - rightHeight);

//         bool currNode = (diff <= 1);
//         //recursion
//         bool leftans = isBalanced(root->left);
//         bool rightans = isBalanced(root->right);

//         if(currNode && leftans && rightans){
//             return true;
//         }else{
//             return false;
//         } 


//     }
// };




//this we are making in O(n);


class Solution{
    public:
        bool isbalanced = true;
        int height(TreeNode* root){
            if(!root)
                return 0;

            int lh = height(root->left);
            int rh = height(root->right);


            //check for current node is it balanced or not
            if(isbalanced && abs(lh-rh) > 1){
                isbalanced = false;
            }
            return max(lh, rh)+1;
        };

    bool isBalanced(TreeNode* root){
        height(root);
        return isbalanced;
    }
} ; 