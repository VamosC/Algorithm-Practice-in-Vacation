/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> table;
        for (auto v : nums)
        {
            if (table.count(v) != 0)
                return true;
            table[v] = 1;
        }
        return false;
    }
};
