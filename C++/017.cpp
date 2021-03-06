/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        // 先构造头结点
        ListNode *pre = new ListNode(0);
        ListNode *p = pre;
        while(pHead1 != NULL && pHead2 != NULL)
        {
            if(pHead1 -> val > pHead2 -> val)
            {
                p -> next = pHead2;
                pHead2 = pHead2->next;
            }
            else
            {
                p -> next = pHead1;
                pHead1 = pHead1->next;
            }
            p = p->next;
        }
        while(pHead1 != NULL)
        {
            p -> next = pHead1;
            pHead1 = pHead1 -> next;
            p = p->next;
        }
        while(pHead2 != NULL)
        {
            p -> next = pHead2;
            pHead2 = pHead2 -> next;
            p = p->next;
        }
        return pre->next;
    }
};