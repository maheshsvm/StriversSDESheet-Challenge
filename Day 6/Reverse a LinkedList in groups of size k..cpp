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
    void reverse(ListNode* s , ListNode* e){
        ListNode *cur = s , *prev = nullptr;

        while(prev != e){
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next || k == 1) return head;
        
        int i = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* beforeStart = dummy;
        beforeStart->next = head;
        ListNode* e = head;

        while(e){
            i++;
            if(i % k == 0){
                // we have to reverse here
                ListNode* s = beforeStart->next , *temp = e->next;
                reverse(s , e);
                beforeStart->next = e;
                s->next = temp;
                beforeStart = s;
                e = temp;
            }
            else{
                e = e->next;
            }
        }

        return dummy->next;

    }
};