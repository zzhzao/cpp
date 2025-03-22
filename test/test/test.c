#define _CRT_SECURE_NO_WARNINGS 1

#include"test.h"

//后插法创建一个链表
void CreateList_R(LinkList* L, int n)
{
    *L = (LNode*)malloc(sizeof(LNode));
    (*L)->next = NULL;
    LNode* r = *L;
    for (int i = 0; i < n; ++i)
    {
        LNode* p = (LNode*)malloc(sizeof(LNode));
        printf("请输入第%d个元素的值：", i + 1);
        scanf("%d", &(p->data));
        p->next = NULL;r->next = p;
        r = p;
    }
}

//输出线性表的元素
void  Print_list(LinkList  L)
{
    LinkList p;
    for (p = L->next;p != NULL; p = p->next) {
        printf("%d", p->data);
    }
}

//取值
Status GetElem(LinkList  L, int i, ElemType e)
{
    LNode* p = L->next;int j = 1;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return ERROR;
    e = p->data;
    return OK;
}

//查找
LNode* LocateElem(LinkList  L, ElemType e)
{
    LNode* p = L->next;
    while (p && p->data != e)
        p = p->next;
    return p;
}


//插入
Status  ListInsert(LinkList  L, int i, ElemType e)
{
    LNode* p = L;  int j = 0;
    while (p && (j < i - 1))
    {
        p = p->next;++j;
    }
    if (!p || j > i - 1)
        return ERROR;
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

//删除
Status ListDelete(LinkList* L, int i) {
    LNode* p = *L;int j = 0;
    while ((p->next) && (j < i - 1))
    {
        p = p->next;++j;
    }
    if (!(p->next) || (j > i - 1))  return ERROR;
    LNode* q = p->next;
    p->next = q->next;
    free(q);
    return OK;
}
