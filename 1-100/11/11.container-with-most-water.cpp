/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
auto static speed = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int maxArea = 0;
        for (int i = 0, j = height.size() - 1; i < j;)
        {
            if (height[i] < height[j])
            {
                int area = height[i] * (j - i);
                if (area > maxArea)
                    maxArea = area;
                i++;
            }
            else
            {
                int area = height[j] * (j - i);
                if (area > maxArea)
                    maxArea = area;
                j--;
            }
        }
        return maxArea;
    }
};
// @lc code=end
