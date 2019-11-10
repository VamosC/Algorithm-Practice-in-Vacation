/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        if (nums.empty())
            return res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 3; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int sum = target - nums[i] - nums[j];
                int front = j + 1, back = n - 1;
                while (front < back)
                {
                    int v0 = nums[front];
                    int v1 = nums[back];
                    int twosum = v0 + v1;
                    if (twosum < sum)
                    {
                        front++;
                    }
                    if (twosum > sum)
                    {
                        back--;
                    }
                    if (twosum == sum)
                    {
                        res.push_back({nums[i], nums[j], v0, v1});
                        while (front < back && nums[++front] == v0)
                            ;
                        while (front < back && nums[--back] == v1)
                            ;
                    }
                }
                while (j < n - 1 && nums[j + 1] == nums[j])
                    j++;
            }
            while (i < n - 1 && nums[i + 1] == nums[i])
                i++;
        }
        return res;
    }
};
// @lc code=end
