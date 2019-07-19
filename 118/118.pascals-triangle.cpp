/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        for (auto i = 0; i < numRows; i++)
        {
            if (i == 0)
                res.push_back(vector<int>{1});
            else if (i == 1)
                res.push_back(vector<int>{1, 1});
            else
            {
                vector<int> tmp;
                tmp.push_back(1);
                for (auto j = 0; j < i - 1; j++)
                {
                    tmp.push_back(res[i - 1][j] + res[i - 1][j + 1]);
                }
                tmp.push_back(1);
                res.push_back(move(tmp));
            }
        }
        return res;
    }
};
