/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    
Node* merge(Node *a , Node *b){
    Node* dummy = new Node(-1);
    Node *res = dummy;
    
    while(a && b){
        if(a->data < b->data){
            res->bottom = a;
            a = a->bottom;
            res = res->bottom;
        }
        else{
            res->bottom = b;
            b = b->bottom;
            res = res->bottom;
        }
    }
    if(a) res->bottom = a;
    else res->bottom = b;
    return dummy->bottom;
}
Node *flatten(Node *root)
{
   if(root == nullptr || root->next == nullptr) return root;
   
   root->next = flatten(root->next);
   
   root = merge(root , root->next);
   
   return root;
}