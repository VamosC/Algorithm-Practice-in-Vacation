/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        generate(candidates, target, tmp, res, 0);
        return res;
    }

private:
    void generate(vector<int> &v, int t, vector<int> &tmp, vector<vector<int>> &res, int k)
    {
        if (t == 0)
        {
            res.push_back(tmp);
            return;
        }
        for (int i = k; i < v.size(); i++)
        {
            if (v[i] > t)
                continue;
            if (i - 1 >= k && v[i - 1] == v[i])
                continue;
            tmp.push_back(v[i]);
            generate(v, t - v[i], tmp, res, i + 1);
            tmp.pop_back();
        }
    }
};
// @lc code=end
