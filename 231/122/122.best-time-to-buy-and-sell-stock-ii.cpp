/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
            return 0;
        auto res = 0;
        for (auto i = 0; i < prices.size() - 1; i++)
        {
            res += ((prices[i + 1] - prices[i] > 0) ? prices[i + 1] - prices[i] : 0);
        }
        return res;
    }
};
