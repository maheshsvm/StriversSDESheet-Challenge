class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        map<int , int> mp;
        queue<pair<Node* , int>> q;
        vector<int> ans;
        q.push({root , 0});
        while(!q.empty()){
            Node * node = q.front().first;
            int vertical = q.front().second;
            q.pop();
            mp[vertical] = node->data;
            if(node->left) q.push({node->left , vertical - 1});
            if(node->right) q.push({node->right , vertical+1});
        }
        
        for(auto p : mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};