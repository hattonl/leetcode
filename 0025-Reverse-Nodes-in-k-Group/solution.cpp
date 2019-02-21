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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0);

        ListNode *tail = dummy;
        ListNode *newTail = NULL;
        ListNode *cur = NULL;

        dummy->next = head;
        cur = head;

        while(tail != NULL)
        {
            ListNode *check = cur;
            newTail = cur;
            
            if (checkKNodes(cur, k) == false) break;
            
            for (int i = k; i > 0 && cur != NULL; --i)
            {
                ListNode *insert = cur;
                cur = cur->next;

                insert->next = tail->next;
                tail->next = insert;
            }
            if (newTail != NULL)
                newTail->next = cur;
            tail = newTail;
        }


        return dummy->next;
    }
    
private:    
    bool checkKNodes(ListNode* head, int k)
    {
        ListNode *check = head;
        int i = k;
        
        while (i>0 && check != NULL)
        {
            --i;
            check = check->next;
        }
        
        return (i==0? true: false);
    }
};
