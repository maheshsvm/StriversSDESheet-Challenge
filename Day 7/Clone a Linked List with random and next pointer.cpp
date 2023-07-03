/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr){
            return nullptr;
        }
        Node * ptr = head;
        while(ptr){
            Node * temp = ptr->next;
            ptr->next = new Node(ptr->val);
            ptr->next->next = temp;
            ptr = temp;
        }

        // arranging random pointers of copied list
        ptr = head;
        while(ptr){
            if(ptr->random != nullptr){
                ptr->next->random = ptr->random->next;
            }
            ptr = ptr->next->next;
        }

        Node * copyListHead = head->next;
        Node * ptrCopyList = copyListHead;
        Node * ptrOriginalList = head;
        while(ptrCopyList->next){
            ptrOriginalList->next = ptrCopyList->next;
            ptrCopyList->next = ptrCopyList->next->next;
            ptrOriginalList = ptrOriginalList->next;
            ptrCopyList = ptrCopyList->next;
        }
        ptrOriginalList->next = nullptr;
        return copyListHead;
    }
};