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
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode* dummy = new ListNode(-1);
        ListNode *res = dummy;
        
        while(a && b){
            if(a->val < b->val){
                res->next = a;
                a = a->next;
                res = res->next;
            }
            else{
                res->next = b;
                b = b->next;
                res = res->next;
            }
        }
        if(a) res->next = a;
        else res->next = b;
        return dummy->next;
    }
};