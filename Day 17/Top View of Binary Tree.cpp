/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        map<int , int> mp;
        queue<pair<Node* , int>> q;
        vector<int> ans;
        q.push({root , 0});
        while(!q.empty()){
            Node * node = q.front().first;
            int vertical = q.front().second;
            q.pop();
            if(mp.find(vertical) == mp.end()) mp[vertical] = node->data;
            if(node->left) q.push({node->left , vertical - 1});
            if(node->right) q.push({node->right , vertical+1});
        }
        
        for(auto p : mp){
            ans.push_back(p.second);
        }
        return ans;
    }

};
