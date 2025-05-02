#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#define MaxL 100

typedef struct node {
    int start, length;
} RecType;

// 比较两个字符串
int StringComp(char S[], RecType A[], int s1, RecType tmp) {
    char str1[MaxL], str2[MaxL];
    int i, j;
    for (j = 0, i = A[s1].start; i < A[s1].start + A[s1].length; i++, j++)
        str1[j] = S[i];
    str1[j] = '\0';
    for (j = 0, i = tmp.start; i < tmp.start + tmp.length; i++, j++)
        str2[j] = S[i];
    str2[j] = '\0';
    return strcmp(str1, str2);
}

// 快速排序算法
void QuickSort(char S[], RecType A[], int low, int high) {
    int i, j;
    RecType tmp;
    i = low;
    j = high;
    if (low < high) {
        tmp = A[low];
        //=================Begin=================
        while (i < j) {

            while (i < j && StringComp(S, A[j], i, tmp) >= 0) {

                j--;

            }

            if (i < j) {

                A[i] = A[j];

                i++;

            }

            while (i < j && StringComp(S, A[i], i, tmp) <= 0) {

                i++;

            }

            if (i < j) {

                A[j] = A[i];

                j--;

            }

        }

        A[i] = tmp;

        // 递归调用

        QuickSort(S, A, low, i - 1);

        QuickSort(S, A, i + 1, high);







        //==================END==================
    }
}

// 清空输入缓冲区
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    char S[MaxL];
    int n, i, j;
    RecType A[MaxL];  // 使用固定大小数组

    // 输入主字符串
    printf("请输入主字符串（最大长度%d）：\n", MaxL - 1);
    fgets(S, MaxL, stdin);
    S[strcspn(S, "\n")] = '\0';  // 移除换行符

    // 输入子字符串数量
    printf("请输入子字符串数量：");
    while (scanf("%d", &n) != 1 || n <= 0 || n > MaxL) {
        clearInputBuffer();
        printf("输入无效，请重新输入（1-%d）：", MaxL);
    }
    clearInputBuffer();

    // 输入每个子字符串信息
    for (i = 0; i < n; i++) {
        int valid = 0;
        while (!valid) {
            printf("输入第%d个子字符串（起始位置 长度）：", i + 1);
            if (scanf("%d %d", &A[i].start, &A[i].length) != 2) {
                clearInputBuffer();
                printf("格式错误，请使用数字输入！\n");
                continue;
            }

            // 验证输入有效性
            if (A[i].start < 0 || A[i].length <= 0) {
                printf("起始位置不能为负，长度必须为正！\n");
            }
            else if (A[i].start + A[i].length > strlen(S)) {
                printf("超出主字符串范围（主字符串长度=%zu）！\n", strlen(S));
            }
            else {
                valid = 1;
            }
            clearInputBuffer();
        }
    }

    // 显示排序前结果
    printf("\n排序前的字符串：\n");
    for (i = 0; i < n; i++) {
        printf("  %2d. [%2d,%2d]: ", i + 1, A[i].start, A[i].length);
        for (j = A[i].start; j < A[i].start + A[i].length; j++)
            printf("%c", S[j]);
        printf("\n");
    }

    // 执行排序
    QuickSort(S, A, 0, n - 1);

    // 显示排序后结果
    printf("\n排序后的字符串：\n");
    for (i = 0; i < n; i++) {
        printf("  %2d. [%2d,%2d]: ", i + 1, A[i].start, A[i].length);
        for (j = A[i].start; j < A[i].start + A[i].length; j++)
            printf("%c", S[j]);
        printf("\n");
    }

    return 0;
}