/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */
class Solution
{
public:
    int countPrimes(int n)
    {
        if (n == 0 || n == 1)
            return 0;
        vector<int> visit(n, 0);
        auto count = 0;
        for (auto i = 2; i < n; i++)
        {
            if (visit[i] != 1)
            {
                count++;
                for (auto j = 2; i * j < n; j++)
                {
                    visit[i * j] = 1;
                }
            }
        }
        return count;
    }
};
