/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */
class Solution
{
public:
    string addBinary(string a, string b)
    {
        static unordered_map<int, string> int2str = {
            {0, "0"},
            {1, "1"}};
        static unordered_map<char, int> char2int = {
            {'0', 0},
            {'1', 1}};
        string res;
        auto carry = 0;
        int i, j;
        for (i = a.size() - 1, j = b.size() - 1; i >= 0 && j >= 0; i--, j--)
        {
            res.insert(0, int2str[char2int[a[i]] ^ char2int[b[j]] ^ carry]);
            carry = (char2int[a[i]] & char2int[b[j]]) | (carry & char2int[a[i]]) | (carry & char2int[b[j]]);
        }
        while (i >= 0)
        {
            res.insert(0, int2str[char2int[a[i]] ^ carry]);
            carry = char2int[a[i]] & carry;
            i--;
        }
        while (j >= 0)
        {
            res.insert(0, int2str[char2int[b[j]] ^ carry]);
            carry = char2int[b[j]] & carry;
            j--;
        }
        if (carry == 1)
            res.insert(0, int2str[carry]);
        return res;
    }
};
