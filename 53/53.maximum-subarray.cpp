/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        auto max_sum = INT_MIN;
        auto sum = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] > max_sum)
                max_sum = nums[i];
            sum += nums[i];
            if (sum <= 0)
                sum = 0;
            else
                max_sum = max(sum, max_sum);
        }
        return max_sum;
    }
};
