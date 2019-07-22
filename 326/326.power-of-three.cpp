/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 */
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if(n == 0)
        return false;
        if (n == INT_MAX || n == INT_MIN)
            return false;
        if(n == 27 || n == 81 || n == 243)
        return true;
        return !(n & (n-1) & (n-2));
    }
};
