/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
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
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return;
        if (n == 2)
        {
            swap(&nums[0], &nums[1]);
            return;
        }
        int u = 0, v = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
            {
                v += 1;
            }
            else if (nums[i] == nums[i - 1])
            {
                if (i - 2 >= 0 && nums[i - 2] < nums[i - 1])
                {
                    u = i - 2;
                    v = -1;
                }
                if (i + 1 <= n - 1 && nums[i + 1] > nums[i])
                    v = i + 1;
            }
            else
            {
                if (i - 2 >= 0 && nums[i - 2] < nums[i - 1])
                {
                    u = i - 2;
                    v = -1;
                }
                if (i + 1 <= n - 1 && nums[i + 1] > nums[i])
                    v = i;
            }
        }
        if (u == 0 && v == 0)
        {
            sort(nums.begin(), nums.end());
        }
        else if (u < v)
        {
            swap(&nums[nums.size() - 1], &nums[nums.size() - 2]);
        }
        else
        {
            int min = nums[u];
            int index = -1;
            for (int k = u + 1; k < n; k++)
            {
                if (nums[k] > nums[u] && (min == nums[u] || nums[k] < min))
                {
                    index = k;
                    min = nums[k];
                }
            }
            swap(&nums[u], &nums[index]);
            sort(nums.begin() + u + 1, nums.end());
        }
    }

private:
    void swap(int *x, int *y)
    {
        int tmp = *x;
        *x = *y;
        *y = tmp;
    }
};

// @lc code=end
