/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        if (nums.empty())
            return 0;
        auto i = 0, j = 0;
        while (true)
        {
            while ((j < nums.size()) && (nums[j] == val))
                j++;
            if (j >= nums.size())
                break;
            nums[i++] = nums[j++];
        }
        return i;
    }
};
