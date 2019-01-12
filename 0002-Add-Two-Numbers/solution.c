/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
    Explanation: 342 + 465 = 807.
*/

/* 输入非负数 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode *pL1   = l1;
    struct ListNode *pL2   = l2;
    struct ListNode *pL3   = NULL;
    struct ListNode *pTail = NULL; 
    struct ListNode *pNode = NULL;

    int val1      = 0;
    int val2      = 0;
    int val       = 0;
    int carryFlag = 0;

    while (pL1 != NULL || pL2 != NULL || carryFlag != 0)
    {
        val1 = (pL1 == NULL)? 0: pL1->val;
        val2 = (pL2 == NULL)? 0: pL2->val;

        val = val1 + val2 + carryFlag;
        if (val >= 10)
        {
            val -= 10;
            carryFlag = 1;
        }
        else
            carryFlag = 0;

        pNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        pNode->val  = val;
        pNode->next = NULL;

        if (pL3 == NULL)
        {
            pL3 = pNode;
            pTail = pNode;
        }
        else
        {
            pTail->next = pNode;
            pTail = pNode;
        }

        if (pL1) 
            pL1 = pL1->next;
        if (pL2)
            pL2 = pL2->next;
    }

    return pL3;
}

