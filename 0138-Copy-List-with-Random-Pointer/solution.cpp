/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        
        RandomListNode *cur = head;
        RandomListNode *dummy = new RandomListNode(0);
        RandomListNode *tail = dummy;
        
        while(cur != NULL)
        {
            RandomListNode *insert = new RandomListNode(cur->label);
            
            insert->next = cur->next;
            cur->next = insert;
            cur = cur->next->next;
        }
        
        cur = head;
        while (cur != NULL)
        {
            if (cur->random != NULL)
                cur->next->random = cur->random->next;
            
            cur = cur->next->next;
        }
        
        cur = head;
        while(cur != NULL)
        {
            tail->next = cur->next;
            cur->next = cur->next->next;
            
            cur = cur->next;
            tail = tail->next;
        }
        
        return dummy->next;
        
    }
};
