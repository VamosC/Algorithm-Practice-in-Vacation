/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */
class Solution
{
private:
    unordered_map<char, int> table{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

public:
    int romanToInt(string s)
    {
        if (s.empty())
            return 0;
        auto result = 0;
        for (auto i = 0; i < s.size(); i++)
        {
            if (s[i] == 'I' && i + 1 < s.size() && s[i + 1] == 'V')
            {
                result += 4;
                i++;
            }
            else if (s[i] == 'I' && i + 1 < s.size() && s[i + 1] == 'X')
            {
                result += 9;
                i++;
            }
            else if (s[i] == 'X' && i + 1 < s.size() && s[i + 1] == 'L')
            {
                result += 40;
                i++;
            }
            else if (s[i] == 'X' && i + 1 < s.size() && s[i + 1] == 'C')
            {
                result += 90;
                i++;
            }
            else if (s[i] == 'C' && i + 1 < s.size() && s[i + 1] == 'D')
            {
                result += 400;
                i++;
            }
            else if (s[i] == 'C' && i + 1 < s.size() && s[i + 1] == 'M')
            {
                result += 900;
                i++;
            }
            else
            {
                result += table[s[i]];
            }
        }
        return result;
    }
};
