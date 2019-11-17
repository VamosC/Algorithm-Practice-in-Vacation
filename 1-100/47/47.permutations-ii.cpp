/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
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
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> res;
        if (nums.empty())
            return res;
        vector<int> tmp;
        vector<bool> s(nums.size(), false);
        sort(nums.begin(), nums.end());
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
            if (i - 1 >= 0 && !s[i - 1] && v[i] == v[i - 1])
                continue;
            s[i] = true;
            tmp.push_back(v[i]);
            generate(v, tmp, s, res, k + 1);
            tmp.pop_back();
            s[i] = false;
        }
    }
};
// @lc code=end
