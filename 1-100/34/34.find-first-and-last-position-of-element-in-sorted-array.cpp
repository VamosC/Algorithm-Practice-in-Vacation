/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
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
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int l = 0, r = n - 1;
        int pos = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] > target)
                r = mid - 1;
            else if (nums[mid] < target)
                l = mid + 1;
            else
            {
                pos = mid;
                break;
            }
        }
        if (pos == -1)
            return vector<int>{-1, -1};
        int start = pos;
        while (start - 1 >= 0 && nums[--start] == target)
            ;
        int end = pos;
        while (end + 1 < n && nums[++end] == target)
            ;
        if (nums[start] != target)
            start++;
        if (nums[end] != target)
            end--;
        return vector<int>{start, end};
    }
};
// @lc code=end
