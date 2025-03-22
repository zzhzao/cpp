#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef int Status;

#define OK 1
#define ERROR 0
typedef  int  ElemType;
typedef   struct    LNode
{
    ElemType  data;
    struct  LNode* next;
} LNode, * LinkList;