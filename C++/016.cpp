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
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL || pHead->next == NULL) return pHead;
        ListNode *pAhead = pHead->next, *pBehind = pHead, *pTem = pHead;
        pHead -> next = NULL;
        while(pAhead != NULL)
        {
            pTem = pAhead->next;
            pAhead-> next = pBehind;
            pBehind = pAhead;
            pAhead = pTem;
        }
        return pBehind;
    }
};