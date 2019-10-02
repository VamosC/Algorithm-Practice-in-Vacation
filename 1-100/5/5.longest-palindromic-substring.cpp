/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
auto static speed = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
};
class Solution
{
public:
    string longestPalindrome(string s)
    {
        vector<char> v;
        v.push_back('#');
        for (auto c : s)
        {
            v.push_back(c);
            v.push_back('#');
        }
        vector<int> p(v.size(), 0);
        int center = -1;
        int r = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (i - center <= r)
            {
                if (p[center - (i - center)] + i < center + r)
                {
                    p[i] = p[center - (i - center)];
                }
                else
                {
                    int j = center + r - i;
                    calPalindrome(v, i, j);
                    center = i;
                    r = j;
                    p[center] = r;
                }
            }
            else
            {
                int j = 1;
                calPalindrome(v, i, j);
                center = i;
                r = j;
                p[center] = r;
            }
        }
        int maxcenter = 0;
        int maxr = 0;
        for (int i = 0; i < p.size(); i++)
        {
            if (p[i] > maxr)
            {
                maxcenter = i;
                maxr = p[i];
            }
        }
        string res;
        for (int i = maxcenter - maxr; i <= maxcenter + maxr; i++)
        {
            if (v[i] != '#')
                res.push_back(v[i]);
        }
        return res;
    }
    void calPalindrome(const vector<char> &v, int center, int &r)
    {
        while (true)
        {
            if (center + r < v.size() && center - r >= 0)
            {
                if (v[center + r] != v[center - r])
                {
                    r--;
                    return;
                }
                else
                    r++;
            }
            else
            {
                r--;
                return;
            }
        }
    }
};

// @lc code=end
