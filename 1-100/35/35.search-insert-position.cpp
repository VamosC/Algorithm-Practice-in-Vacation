/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return target <= nums[0] ? 0 : 1;
        auto j = nums.size() - 1;
        decltype(j) i = 0;
        while (i < j)
        {
            auto mid = (i + j) / 2;
            if (nums[mid] < target)
                i = mid + 1;
            else if (nums[mid] == target)
            {
                return mid;
            }
            else
                j = mid;
        }
        return nums[i] < target ? i + 1 : i;
    }
};
