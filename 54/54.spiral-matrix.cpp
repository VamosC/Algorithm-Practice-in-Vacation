/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        if (matrix.empty())
            return res;
        int px = 0, py = 0;
        vector<vector<bool>> s;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < matrix.size(); i++)
        {
            s.emplace_back(matrix[i].size(), true);
        }
        while (true)
        {
            while (py < n && s[px][py])
            {
                res.push_back(matrix[px][py]);
                s[px][py] = false;
                py++;
            }
            py--;
            px++;
            while (px < m && s[px][py])
            {
                res.push_back(matrix[px][py]);
                s[px][py] = false;
                px++;
            }
            px--;
            py--;
            while (py >= 0 && s[px][py])
            {
                res.push_back(matrix[px][py]);
                s[px][py] = false;
                py--;
            }
            py++;
            px--;
            while (px >= 0 && s[px][py])
            {
                res.push_back(matrix[px][py]);
                s[px][py] = false;
                px--;
            }
            px++;
            if (py + 1 < n && s[px][py + 1])
            {
                py++;
                continue;
            }
            break;
        }
        return res;
    }
};
// @lc code=end
