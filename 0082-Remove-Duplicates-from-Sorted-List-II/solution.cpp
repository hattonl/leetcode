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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = dummy;

        while (cur != NULL && cur->next != NULL && cur->next->next != NULL)
        {
            if (cur->next->val == cur->next->next->val)
            {
                int val = cur->next->val;
                while (cur->next != NULL && cur->next->val == val)
                    cur->next = cur->next->next;
            }
            else
                cur = cur->next;
            
        }

        return dummy->next;
    }
};
