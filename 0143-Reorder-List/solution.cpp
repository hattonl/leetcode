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
    void reorderList(ListNode* head) {
        ListNode *scan = head;
        ListNode *scd = head;
        ListNode *pri = NULL;
        
        if (head == NULL || head->next == NULL) return;
        
        while (scan != NULL && scan->next != NULL)
        {
            scan = scan->next->next;
            pri = scd;
            scd = scd->next;
        }
        
        pri->next = NULL;
        
        // reverse List-scd
        scd = reverseList(scd);
        // 
        
        head = mergeTwoList(head, scd);
        
        // return head;
    }
    
    ListNode *reverseList(ListNode *head)
    {
        ListNode *tail = head;
        ListNode *pri = NULL;
        ListNode *nxt = head;
        
        if (head != NULL) nxt = head->next;
        
        while (nxt != NULL)
        {
            pri = head;
            head = nxt;
            nxt = head->next;
            head->next = pri;
        }
        
        tail->next = NULL;
        return head;
    }
    
    ListNode *mergeTwoList(ListNode *one, ListNode *two)
    {
        
        ListNode *head = one;
        
        ListNode *insertNode = NULL;
        
        while(one != NULL && two != NULL)
        {
            insertNode = two;
            two = two->next;
            
            insertNode->next = one->next;
            one->next = insertNode;
            
            one = one->next->next;
        }
                
        if (one == NULL && two != NULL)
            insertNode->next = two;
        
        return head;
    }
};