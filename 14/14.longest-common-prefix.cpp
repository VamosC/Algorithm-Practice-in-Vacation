/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";
        if (strs.size() == 1)
            return strs[0];
        if (strs[0].size() < 1)
            return "";
        auto i = 1;
        while (true)
        {
            auto flag = false;
            for (auto j = 1; j < strs.size(); j++)
            {
                if (strs[0].size() < i || strs[j].size() < i || memcmp(strs[0].data(), strs[j].data(), i) != 0)
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
            i++;
        }
        return string(strs[0], 0, i - 1);
    }
};
