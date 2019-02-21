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
    ListNode* partition(ListNode* head, int x) {
        ListNode *less    = new ListNode(0);
        ListNode *greater = new ListNode(0);
        ListNode *lessTail = less;
        ListNode *greatTail = greater;
        
        ListNode *cur = head;
        
        while (cur != NULL)
        {
            ListNode *nxt = cur->next;
            
            if (cur->val < x)
            {
                cur->next = lessTail->next;
                lessTail->next = cur;
                lessTail = lessTail->next;
            }
            else
            {
                cur->next = greatTail->next;
                greatTail->next = cur;
                greatTail = greatTail->next;
            }
            
            cur = nxt;
        }
        
        lessTail->next = greater->next;
        greatTail->next = NULL;
        
        return less->next;
    }
};