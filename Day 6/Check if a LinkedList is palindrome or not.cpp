/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    void reverseList(ListNode* &newHead , ListNode* p){
        if(p->next == NULL){
            newHead = p;
            return;
        }
        reverseList(newHead , p->next);
        ListNode* q = p->next;
        q->next = p;
        p->next = NULL;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL){
            return true;
        }
        ListNode *slow = head , *fast = head;
        ListNode * prevSlow;
        while(fast && fast->next){
            prevSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode * newHead;
        if(fast == NULL){
            reverseList(newHead , slow);
        }
        else{
             reverseList(newHead , slow->next);
        }
        prevSlow->next = NULL;
        while(head && newHead){
            if(head->val == newHead->val){
                head = head->next;
                newHead = newHead->next;
            }
            else{
                return false;
            }
        }
        return true;
    }
};