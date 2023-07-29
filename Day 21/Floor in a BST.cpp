int floorInBST(TreeNode<int> * root, int x)
{
    // Write your code here.
        TreeNode<int>* pre = nullptr;
        while(root){
            if(root->val > x){
                root = root->left;
            }
            else{
                pre = root;
                root = root->right;
            }
        }
        return pre->val;
}