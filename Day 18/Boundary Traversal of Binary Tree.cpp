#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

bool isLeaf(TreeNode<int>* root){
    return !root->left && !root->right;
}
void addLeftBoundary(TreeNode<int>* root , vector<int>&res){
    TreeNode<int>* cur = root->left;
    while(cur){
        if(!isLeaf(cur)) res.push_back(cur->data);
        if(cur->left) cur = cur->left;
        else cur = cur->right;
    }
}

void addLeaves(TreeNode<int>* root , vector<int>&res){
    if(!root) return;
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    addLeaves(root->left , res);
    addLeaves(root->right , res);
}

void addRightBoundary(TreeNode<int>* root , vector<int>&res){
    vector<int> temp;
    TreeNode<int>* cur = root->right;
    while(cur){
        if(!isLeaf(cur)) temp.push_back(cur->data);
        if(cur->right) cur = cur->right;
        else cur = cur->left; 
    }
    reverse(temp.begin() , temp.end());
    res.insert(res.end() , temp.begin() , temp.end());
}
vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> res;
    if(!isLeaf(root)) res.push_back(root->data);
    
    addLeftBoundary(root , res);
    addLeaves(root , res);
    addRightBoundary(root , res);
    return res;
}