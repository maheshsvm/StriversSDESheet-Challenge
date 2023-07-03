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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ahead = head , * cur = head , *temp = head;

        while(n--) ahead = ahead->next;
        while(ahead){
            temp = cur;
            cur = cur->next;
            ahead = ahead->next;
        }
        if(cur == head) head = head->next;
        temp->next = cur->next;
        cur->next = nullptr;
        delete cur;
        return head;
    }
};