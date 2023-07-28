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
class Solution {
private:
    int solve(TreeNode* root , int& dia){
        if(!root ) return 0;
        int lh = solve(root->left , dia);
        int rh = solve(root->right , dia);
        dia = max(dia , lh + rh);
        return 1 + max(lh , rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = INT_MIN;
        solve(root , diameter);
        return diameter;
    }
};