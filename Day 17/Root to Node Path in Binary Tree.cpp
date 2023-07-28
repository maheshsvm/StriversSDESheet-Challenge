#include <bits/stdc++.h> 
/********************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    
********************************************************************/
bool isLeaf(BinaryTreeNode < int >* root){
    return !root->left && !root->right;
}
void solve(BinaryTreeNode < int >* root , string ds , vector<string>& ans){
    if(!root) return;
    if(isLeaf(root)){
        ans.push_back(ds + to_string(root->data));
        return;
    }
    ds += (to_string(root->data) + " ");

    solve(root->left , ds , ans);
    solve(root->right , ds , ans);
}
vector < string > allRootToLeaf(BinaryTreeNode < int > * root) {
    // Write your code here.
    vector<string>ans;
    string ds = "";
    solve(root , ds , ans);
    return ans;

}