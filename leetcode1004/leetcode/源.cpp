#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ret = 0;
        for (int left = 0, right = 0, zero = 0;right < nums.size();right++)
        {
            if (nums[right] == 0) zero++;
            while (zero > k)
                if (nums[left++] == 0) zero--;
            ret = max(ret, right - left + 1);
        }
        return ret;
    }
};