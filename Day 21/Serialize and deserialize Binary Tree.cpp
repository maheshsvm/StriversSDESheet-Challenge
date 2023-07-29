/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string ans = string();
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node != NULL){
                if(ans.size() == 0) ans += to_string(node->val);
                else ans += ',' + to_string(node->val);
            }
            else{
                if(ans.size() == 0) ans += '#';
                else ans += ",#";
            }

            if(node != NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)return nullptr;
        queue<TreeNode*> q;
        stringstream s(data);
        string str;
        getline(s , str , ',');

        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            // attaching left child
            getline(s  , str , ',');
            if(str != "#"){
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }

            //attaching right child
            getline(s  , str , ',');
            if(str != "#"){
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));