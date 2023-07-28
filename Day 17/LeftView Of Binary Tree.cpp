

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
    if(!root) return ans;

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        ans.push_back(q.front()->data);
        while(size--){
            Node* node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

    }
    return ans;
}