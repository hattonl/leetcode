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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        int reverseNums = n - m + 1;
        ListNode *dummy = new ListNode(0);
        ListNode *newTail = NULL;
        ListNode *tail = NULL;
        ListNode *cur = NULL;
        
        dummy->next = head;
        newTail = dummy;
        
        while(m--)
        {
            tail = newTail;
            newTail = newTail->next;
        }
        
        cur = newTail->next;
        
        while (--reverseNums)
        {   // insert curNode
            ListNode *nxt = cur->next;
            cur->next = tail->next;
            tail->next = cur;
            
            cur = nxt;
        }
        
        newTail->next = cur;
        
        return dummy->next;
        
    }
};