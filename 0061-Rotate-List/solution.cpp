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
    ListNode* rotateRight(ListNode* head, int k) {
        int listLong = 0;
        ListNode *cur = head;
        ListNode *tail = NULL;
        while(cur != NULL)
        {
            tail = cur;
            cur = cur->next;
            ++listLong;
        }
        
        if (!listLong) 
            return head;
        
        tail->next = head;
        
        k = listLong - (k % listLong);
        
        cur = head;
        while(k--)
        {
            cur = head;
            head = head->next;
        }
        cur->next = NULL;
        return head;
    }
};
