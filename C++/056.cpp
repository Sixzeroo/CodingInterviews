/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    // 采用断开节点的方法
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if (!pHead->next)
            return NULL;
        ListNode* previous = pHead;
        ListNode* front = pHead ->next;
        while (front)
        {
            previous->next = NULL;
            previous = front;
            front = front->next;
        }
        return previous;
    }
};