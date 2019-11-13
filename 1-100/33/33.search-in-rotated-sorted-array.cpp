/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        if (nums.empty())
            return -1;
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[l])
                l = mid;
            else if (nums[mid] < nums[r])
                r = mid;
            else
                l = mid + 1;
        }
        int nl, nr;
        if (target >= nums[0])
        {
            if (target <= nums[l])
            {
                nl = 0;
                nr = l;
            }
            else
            {
                nl = 0;
                nr = l - 1;
            }
        }
        else
        {
            if (target >= nums[l])
            {
                nl = l;
                nr = n - 1;
            }
            else
            {
                nl = l + 1;
                nr = n - 1;
            }
        }
        if (nums[0] <= nums[n - 1])
        {
            nl = 0;
            nr = n - 1;
        }
        while (nl <= nr)
        {
            int mid = (nl + nr) / 2;
            if (nums[mid] < target)
                nl = mid + 1;
            else if (nums[mid] > target)
                nr = mid - 1;
            else
                return mid;
        }
        return -1;
    }
};
// @lc code=end
