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
        string res;
        auto carry = 0;
        int i, j;
        for (i = a.size() - 1, j = b.size() - 1; i >= 0 && j >= 0; i--, j--)
        {
            carry = a[i] & b[j] & carry;
            res.insert(0, '0' + a[i] ^ b[j] ^ carry);
        }
        while (i >= 0)
        {
            carry = a[i] & carry;
            res.insert(0, '0' + a[i] ^ carry);
        }
        while (j >= 0)
        {
            carry = b[j] & carry;
            res.insert(0, '0' + b[j] ^ carry);
        }
        return res;
    }
};
