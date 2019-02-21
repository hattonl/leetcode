/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        dummy->next = head;
        
        while (cur->next != NULL && cur->next->next != NULL)
        {
            ListNode *p1 = cur->next;
            ListNode *p2 = cur->next->next;
            
            p1->next = p2->next;
            p2->next = p1;
            cur->next = p2;
            
            cur = cur->next->next;
        }
        
        return dummy->next;
    }
};