Node* solve(Node* root ,int&k,int node ,int &ans){
    if(!root) return 0;
    if(root->data == node) return root;
    
    auto l = solve(root->left,k,node,ans);
    auto r = solve(root->right,k,node,ans);
    
    //node yahna milegi
    if(l == NULL && r == NULL) return 0 ;
    k--;
    if(k==0){
        ans = root->data;
    }
    
    if(l != NULL && r == NULL){
        return l;
    }else if(l==NULL && r!=NULL) {
        return r;
    }else{
        return root;
    }
}

int kthAncestor(Node *root, int k, int node)
{
    int ans = -1;
    solve(root,k,node,ans);
    return ans;
}
