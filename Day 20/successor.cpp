class Solution
{
    private:
    Node* findSuc(Node* root ,int key){
        Node* suc = NULL;
        while(root){
            if(root->key <= key){
                root = root->right;
            }
            else{
                suc = root;
                root = root->left;
            }
        }
        return suc;
    }
    
    Node* findPre(Node* root , int key){
        Node* pre = nullptr;
        while(root){
            if(root->key >= key){
                root = root->left;
            }
            else{
                pre = root;
                root = root->right;
            }
        }
        return pre;
    }
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        pre = findPre(root , key);
        suc = findSuc(root , key);
    }
};