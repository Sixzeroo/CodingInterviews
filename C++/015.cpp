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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(k==0 || pListHead == NULL)
            return NULL;
        ListNode* pAhead = pListHead, *pBhind = pListHead;
        for(int i=0; i<k-1; i++)
        {
            if(pAhead->next == NULL) return NULL;
            pAhead = pAhead -> next;
        }
        while(pAhead->next != NULL)
        {
            pAhead = pAhead -> next;
            pBhind = pBhind -> next;
        }
        return pBhind;
    }
};