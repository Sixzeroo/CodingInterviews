/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL)
        {
            return NULL;
        }

        RandomListNode *currNode = pHead;
        RandomListNode *newHead = NULL, *preNode = NULL, *newNode = NULL;

        ///  首先复制原链表的普通指针域, 一次遍历即可完成
        ///  将新的节点链接杂原来节点的末尾
        while(currNode != NULL)
        {
            if((newNode = new RandomListNode(currNode->label)) == NULL)
            {
                perror("new error : ");
                exit(-1);
            }


            /// 将新的节点newNode连接在currNode的后面
            newNode->next = currNode->next;
            currNode->next = newNode;

            ///  指向指向下一个节点
            currNode = newNode->next;
        }

        ///  接着复制随机指针域
        ///  原来节点的下一个位置就是其对应的新节点
        currNode = pHead;
        newNode = pHead->next;
        while(currNode != NULL)
        {
            RandomListNode *randNode = currNode->random;                        ///  随机指针域randNode
            RandomListNode *newNode = currNode->next;
            if(randNode != NULL)
            {

                newNode->random = randNode->next;

            }
            else
            {
                newNode->random = NULL;
            }
            ///  链表同步移动
            currNode = newNode->next;
        }

        /// 将链接在一起的新旧两个链表拆分开
        /// 脱链，更新各链表的next指针
        currNode = pHead;
        newNode = newHead = pHead->next;
        while(currNode != NULL)
        {
            /// curr  new new->next
            currNode->next = newNode->next;
            if(newNode->next != NULL)
            {
                newNode->next = newNode->next->next;
            }
            else
            {
                newNode->next = NULL;
            }

            currNode = currNode->next;
            newNode = newNode->next;
        }

        return newHead;
    }
};