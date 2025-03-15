#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void reverse(int* nums, int left, int right)
{
    while (left < right)
    {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
        left++;
        right--;
    }
}
void rotate(int* nums, int numsSize, int k) {

    k = k % numsSize;
    reverse(nums, 0, numsSize - k - 1);
    reverse(nums, numsSize - k, numsSize - 1);
    reverse(nums, 0, numsSize - 1);
}
int main()
{
    int nums[7] = {1,2,3,4,5,6,7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    rotate(nums, numsSize, 3);
    return 0;
}