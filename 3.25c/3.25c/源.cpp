#define _CRT_SECURE_NO_WARNINGS 1#include <functional>
//找到比val小的值放置在前面其余的放置链表后端
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
        ListNode* lesslist = (ListNode*)malloc(sizeof(ListNode));
        ListNode* greaterlist = (ListNode*)malloc(sizeof(ListNode));
        ListNode* lesshead = lesslist;
        ListNode* greaterhead = greaterlist;
        ListNode* pcur = pHead;
        while (pcur)
        {
            if (pcur->val < x)
            {
                lesslist->next = pcur;
                lesslist = lesslist->next;
            }
            else {
                greaterlist->next = pcur;
                greaterlist = greaterlist->next;
            }
            pcur = pcur->next;
        }
        lesslist->next = greaterhead->next;
        greaterlist->next = NULL;
        free(greaterhead);
        greaterhead = NULL;
        ListNode* newhead = lesshead->next;
        free(lesshead);
        lesshead = NULL;
        return newhead;
    }
};



typedef struct Node Node;
struct Node* copyRandomList(struct Node* head) {
    Node* pcur = head;
    while (pcur)
    {
        Node* newnode = (Node*)malloc(sizeof(Node));
        newnode->val = pcur->val;
        newnode->next = pcur->next;
        pcur->next = newnode;
        pcur = pcur->next->next;
    }

    Node* copyhead = head->next;
    Node* copytail = copyhead;
    pcur = head;
    while (pcur)
    {
        copytail->random = pcur->random->next;
        pcur = pcur->next->next;
        copytail = copytail->next->next;
    }
    return copyhead;
}