/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class BSTIterator {
private:
    stack<TreeNode*> st;
    int direction;
public:
    BSTIterator(TreeNode* root , int direction) {
        this->direction = direction;
        if(direction == 0)
            pushAllLeft(root);
        else 
            pushAllRight(root);
    }

    void pushAllLeft(TreeNode* root){
        while(root){
            st.push(root);
            root = root->left;
        }
    }

    void pushAllRight(TreeNode* root){
        while(root){
            st.push(root);
            root = root->right;
        }
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        int val = node->val;
        if(direction == 0 && node->right) pushAllLeft(node->right);
        else if(node->left) pushAllRight(node->left);
        return val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator left(root , 0);
        BSTIterator right(root , 1);
        int i = left.next();
        int j = right.next();
        while(i < j){
            if(i + j == k) return true;
            if(i + j < k) i = left.next();
            else j = right.next(); 
        }
        return false;
    }
};