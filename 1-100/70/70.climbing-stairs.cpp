/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        else if (n == 2)
            return 2;
        vector<int> steps(n + 1, 0);
        steps[0] = 0;
        steps[1] = 1;
        steps[2] = 2;
        for (auto i = 3; i <= n; i++)
        {
            steps[i] = steps[i - 1] + steps[i - 2];
        }
        return steps[n];
    }
};
