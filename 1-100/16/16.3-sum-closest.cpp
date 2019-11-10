/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int diff = 0;
        for (int i = 0; i < n - 2; i++)
        {
            int sum = target - nums[i];
            int front = i + 1, back = n - 1;
            while (front < back)
            {
                int v0 = nums[front], v1 = nums[back];
                int twosum = v0 + v1;
                if (twosum < sum)
                {
                    if (diff == 0)
                        diff = twosum - sum;
                    else if (abs(diff) > sum - twosum)
                        diff = twosum - sum;
                    front++;
                }
                if (twosum > sum)
                {
                    if (diff == 0)
                        diff = twosum - sum;
                    else if (abs(diff) > twosum - sum)
                        diff = twosum - sum;
                    back--;
                }
                if (twosum == sum)
                {
                    return target;
                }
            }
            while (i < n - 1 && nums[i + 1] == nums[i])
                i++;
        }
        return target + diff;
    }
};
// @lc code=end
