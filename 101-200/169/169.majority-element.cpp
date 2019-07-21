/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        sort(nums.begin(), nums.end());
        auto size = nums.size();
        auto j = 0;
        auto i = 0;
        while (true)
        {
            while (i < size && nums[i] == nums[j])
                i++;
            if ((i - j) > size / 2)
                return nums[j];
            else
                j = i;
        }
    }
};
