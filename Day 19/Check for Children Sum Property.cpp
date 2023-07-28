/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
*/
bool isLeaf(Node* root){
    return !root->left && !root->right;
}
bool isParentSum(Node *root){
    // Write your code here.
    if(!root || isLeaf(root)) return true;
    int val = 0;
    if(root->left) val += root->left->data;
    if(root->right) val += root->right->data;
    return (val == root->data) && isParentSum(root->left) && isParentSum(root->right);
}