/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
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
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        if (n == 0)
            return res;
        string s;
        generate(s, n, n, res);
        return res;
    }

private:
    void generate(string &s, int left_remain, int right_remain, vector<string> &res)
    {
        if (left_remain == 0 && right_remain == 0)
        {
            res.push_back(s);
            return;
        }
        if (left_remain > right_remain)
            return;
        if (left_remain > 0)
        {
            s.push_back('(');
            generate(s, left_remain - 1, right_remain, res);
            s.pop_back();
        }
        if (right_remain > 0 && left_remain != right_remain)
        {
            s.push_back(')');
            generate(s, left_remain, right_remain - 1, res);
            s.pop_back();
        }
    }
};
// @lc code=end
