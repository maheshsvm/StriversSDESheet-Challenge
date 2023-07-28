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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool reverse = false;

        while(!q.empty()){
            int n = q.size();
            vector<int> temp(n);
            for(int i = 0; i < n; i++){
                TreeNode* node = q.front();
                q.pop();

                if(reverse == true){
                    temp[n-1-i] = node->val;
                }
                else{
                    temp[i] = node->val;
                }

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            reverse = !reverse;
            ans.push_back(temp);
        }
        return ans;

    }
};