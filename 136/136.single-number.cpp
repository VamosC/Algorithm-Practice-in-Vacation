/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        auto res = 0;
        for (size_t i = 0; i < nums.size(); i++)
            res ^= nums[i];
        return res;
    }
};
