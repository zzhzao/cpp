#define _CRT_SECURE_NO_WARNINGS 1

#include"test.h"
void menu() {
    printf("0.退出程序\n");
    printf("1.创建链表\n");
    printf("2.显示链表\n");
    printf("3.取链表中元素的值\n");
    printf("4.查找链表中的元素\n");
    printf("5.插入\n");
    printf("6.删除\n");
    printf("7.退出系统\n");
}

int main() {
    LinkList L = NULL;
    int choice = 1;
    int  n, i;
    ElemType e;
    LNode* result;
    while (choice) {
        menu();
        printf("请输入你的选择: ");
        scanf("%d", &choice);
        switch (choice) {
        case 0:
            return 0;
        case 1:
            printf("请输入链表元素个数: ");
            scanf("%d", &n);
            CreateList_R(&L, n);
            break;
        case 2:
            Print_list(L);
            break;
        case 3:
            printf("请输入要取值的位置: ");
            scanf("%d", &i);
            if (GetElem(L, i, e) == OK)
                printf("位置 %d 的元素值为: %d\n", i, e);
            else
                printf("位置不合法，取值失败\n");
            break;
        case 4:
            printf("请输入要查找的元素值: ");
            scanf("%d", &e);
            result = LocateElem(L, e);
            if (result)
                printf("元素 %d 存在于链表中\n", e);
            else
                printf("元素 %d 不存在于链表中\n", e);
            break;
        case 5:
            printf("请输入插入位置: ");
            scanf("%d", &i);
            printf("请输入要插入的元素值: ");
            scanf("%d", &e);
            if (ListInsert(L, i, e) == OK)
                printf("插入成功\n");
            else
                printf("插入失败\n");
            break;
        case 6:
            printf("请输入要删除的位置: ");
            scanf("%d", &i);
            if (ListDelete(&L, i) == OK)
                printf("删除成功\n");
            else
                printf("删除失败\n");
            break;
        case 7:
            return 0;
        default:
            printf("无效的选择，请重新输入\n");
        }
    }
    return 0;
}