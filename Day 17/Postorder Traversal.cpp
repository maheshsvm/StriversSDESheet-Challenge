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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        unordered_set<TreeNode*> vis;
        stack<TreeNode*> st;
        TreeNode* cur = root;

        while(true){
            if(cur){
                st.push(cur);
                vis.insert(cur);
                cur = cur->left;
            }
            else{
                while(!st.empty() && (!st.top()->right || ( vis.find(st.top()->right)) != vis.end()) ){
                    ans.push_back(st.top()->val);
                    st.pop();
                }
                if(st.empty()) break;
                cur = st.top()->right;
            }
        }
        return ans;
    }
};