#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[128] = { 0 };
        int left = 0; right = 0;
        int n = s.size();
        int ret = 0;
        while (right < n)
        {
            hash[s[right]]++;
            while (hash[s[right]] > 1)
            {
                hash[s[left]++]--;
            }
            ret = max(ret, right - left + 1);
            right++;
        }
        return ret;
    }
};