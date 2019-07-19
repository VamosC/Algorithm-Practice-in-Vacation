/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        if (s.empty())
            return 0;
        auto i = 0;
        for (i = s.size() - 1; i >= 0; i--)
            if (s[i] != ' ')
                break;
        if (i == -1)
            return 0;
        auto pos = s.find_last_of(' ', i);
        if (pos != string::npos)
        {
            if (pos == s.size() - 1)
                return 0;
            else
                return i - pos;
        }
        else
        {
            return i + 1;
        }
    }
};
