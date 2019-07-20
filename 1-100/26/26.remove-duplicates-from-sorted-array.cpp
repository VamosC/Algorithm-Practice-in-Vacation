/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        auto i = 0, j = 1;
        if (nums.empty())
            return 0;
        while (true)
        {
            while ((j < nums.size()) && (nums[j] == nums[i]))
                j++;
            if (j >= nums.size())
                break;
            nums[++i] = nums[j];
        }
        return i + 1;
    }
};
