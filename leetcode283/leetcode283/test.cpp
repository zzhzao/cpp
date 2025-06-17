#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //int dest = -1;
        //int cur = 0;
        //while (cur < nums.size())
        //{
        //    if (nums[cur] != 0)
        //    {
        //        dest++;
        //        swap(nums[dest], nums[cur]);
        //    }
        //    cur++;
        for(int dest = -1,int cur = 0;cur<nums.size();cur++)
        {
            if (nums[cur] != 0)
            {
                swap(nums[++dest], nums[cur]);
            }
        }
    }
};