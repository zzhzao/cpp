#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m = { {0,-1} };
        int cur = 0, ans = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            nums[i] == 0 ? --cur : ++cur;
            if (m.count(cur))
                ans = max(ans, i - m[cur]);
            else
                m[cur] = i;
        }
        return ans;
    }
};

