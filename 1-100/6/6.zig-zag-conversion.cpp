/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 */

// @lc code=start
class Solution
{
public:
    string convert(string s, int numRows)
    {
        string res;
        if (numRows == 1)
            return s;
        for (int i = 0; i < numRows; i++)
        {
            int j;
            for (j = 0; j < s.size(); j += (2 * numRows - 2))
            {
                if (i != 0 && i != numRows - 1)
                {
                    if (j - i >= 0)
                        res.append(1, s[j - i]);
                }
                if (j + i < s.size())
                    res.append(1, s[j + i]);
            }
            if (i != 0 && i != numRows - 1)
            {
                if (j - i >= 0 && j - i < s.size())
                    res.append(1, s[j - i]);
            }
        }
        return res;
    }
};
// @lc code=end
