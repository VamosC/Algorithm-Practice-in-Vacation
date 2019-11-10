/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start

auto static _ = []() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    return 0;
}();

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        if (nums.empty())
        {
            return res;
        }
        sort(nums.begin(), nums.end());
        int sum = 0;
        unordered_map<int, int> table;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (i != 0 && sum == -nums[i])
                continue;
            sum = -nums[i];
            table.clear();
            if (nums[i + 1] > sum)
                continue;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (table.count(nums[j]) != 0)
                {
                    if (table[nums[j]] != -1)
                    {
                        res.push_back({-sum, nums[j], sum - nums[j]});
                        table[nums[j]] = -1;
                    }
                }
                else
                {
                    table[sum - nums[j]] = 1;
                }
            }
        }
        return res;
    }
};
// @lc code=end
