/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */
class Solution
{
public:
    int titleToNumber(string s)
    {
        auto res = 0;
        for (auto c : s)
        {
            res *= 26;
            res += c - 'A' + 1;
        }
        return res;
    }
};
