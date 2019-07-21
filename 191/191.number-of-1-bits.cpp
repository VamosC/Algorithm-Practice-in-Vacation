/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        auto count = 0;
        for (auto i = 0; i < 32; i++)
        {
            if (n & 1)
                count++;
            n >>= 1;
        }
        return count;
    }
};
