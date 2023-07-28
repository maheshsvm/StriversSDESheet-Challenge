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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> pre;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(true){
            if(cur){
                pre.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }
            else{
                if(st.empty()) break;
                TreeNode* parent = st.top();
                st.pop();
                cur = parent->right;
            }
        }
        return pre;
    }
};