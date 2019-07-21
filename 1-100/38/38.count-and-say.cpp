/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */
class Solution
{
public:
    string countAndSay(int n)
    {
        string s = "1";
        for (auto i = 1; i < n; i++)
        {
            decltype(s) tmp;
            auto k = 0;
            decltype(k) j = 0;
            while (k < s.size())
            {
                while (k < s.size() && s[k] == s[j])
                    k++;
                tmp += ('0' + (k - j));
                tmp += s[j];
                j = k;
            }
            s = move(tmp);
        }
        return s;
    }
};
