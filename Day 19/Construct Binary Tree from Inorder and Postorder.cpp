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
    TreeNode* solve(vector<int>& preorder, int lp , int rp , vector<int>& inorder, int li , int ri , unordered_map<int,int>&inMap){
        if(lp > rp || li > ri) return nullptr;
        if(rp - lp + 1 == 1){
            return new TreeNode(preorder[lp]);
        }
        int i = inMap[preorder[lp]];
        TreeNode* root = new TreeNode(inorder[i]);
        int elementsOnLeft = i - li;
        root->left = solve(preorder , lp+1 , lp+elementsOnLeft , inorder , li , i-1 , inMap);
        root->right = solve(preorder , lp+elementsOnLeft + 1 , rp , inorder , i+1 , ri , inMap);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int , int> inMap;
        int n = inorder.size();
        for(int i = 0; i < n; i++) inMap[inorder[i]] = i;
        TreeNode* root = solve(preorder , 0 , n-1 , inorder , 0 , n-1 , inMap);
        return root;
    }
};