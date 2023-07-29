int findCeil(BinaryTreeNode<int> *root, int data){
    // Write your code here.
        BinaryTreeNode<int>* suc = NULL;
        while(root){
            if(root->data < data){
                root = root->right;
            }
            else{
                suc = root;
                root = root->left;
            }
        }
        return !suc ? -1 : suc->data;
}