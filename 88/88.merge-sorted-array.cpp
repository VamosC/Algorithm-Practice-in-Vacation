/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (auto i = m; i < m + n; i++)
            nums1[i] = nums2[i - m];
        sort(nums1.begin(), nums1.end());
    }
};
