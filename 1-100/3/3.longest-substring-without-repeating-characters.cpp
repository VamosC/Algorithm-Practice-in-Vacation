/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty())
            return 0;
        int start = 0;
        int max = 1;
        unordered_map<int, int> t;
        for (auto i = 0; i < s.length(); i++)
        {
            if (t.count(s[i]) != 0)
            {
                if (t[s[i]] < start)
                {
                    t[s[i]] = i;
                }
                else
                {
                    if (max < i - start)
                        max = i - start;
                    start = t[s[i]] + 1;
                    t[s[i]] = i;
                }
            }
            t[s[i]] = i;
        }
        if (max < s.length() - start)
            max = s.length() - start;
        return max;
    }
};
// @lc code=end
