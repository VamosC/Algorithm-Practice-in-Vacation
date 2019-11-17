/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
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
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        if (nums.empty())
            return res;
        vector<int> tmp;
        vector<bool> s(nums.size(), false);
        generate(nums, tmp, s, res, 0);
        return res;
    }

private:
    void generate(vector<int> &v, vector<int> &tmp, vector<bool> &s, vector<vector<int>> &res, int k)
    {
        if (k == v.size())
        {
            res.push_back(tmp);
            return;
        }
        for (int i = 0; i < v.size(); i++)
        {
            if (s[i])
                continue;
            tmp.push_back(v[i]);
            s[i] = true;
            generate(v, tmp, s, res, k + 1);
            tmp.pop_back();
            s[i] = false;
        }
    }
};
// @lc code=end
