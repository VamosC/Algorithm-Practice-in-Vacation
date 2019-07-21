/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n == 0)
            return false;
        if (n == INT_MIN || n == INT_MAX)
            return false;
        return !(n & (n - 1));
    }
};
