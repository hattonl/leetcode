Given a linked list, remove the *n*-th node from the end of list and return its head.

**Example:**

```
Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
```

**Note:**

Given *n* will always be valid.

**Follow up:**

Could you do this in one pass?

两个指针，快指针先走n步，慢指针再从头走。快指针走到队尾时删除慢指针指向的节点。
申请一个头节点`dummy`以便有删除头节点时的情况。返回时注意返回`dummy->next`。