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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == NULL || pHead2 == NULL)
            return NULL;
        // 计算链表长度
        int len1 = 0, len2 = 0;
        ListNode* tem = pHead1;
        for(tem = pHead1; tem != NULL; tem = tem->next, len1++);
        for(tem = pHead2; tem != NULL; tem = tem->next, len2++);
        // 去掉前面相差的部分
        if(len2 > len1) swap(pHead1, pHead2);
        int d = abs(len1 - len2);
        ListNode* tem1 = pHead1, *tem2 = pHead2;
        while(d--)
        {
            tem1 = tem1->next;
        }
        // 寻找共同的节点
        while(tem1 != tem2)
        {
            tem1 = tem1->next;
            tem2 = tem2->next;
        }
        return tem1;
    }
};