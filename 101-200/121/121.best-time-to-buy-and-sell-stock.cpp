/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
            return 0;
        vector<int> r;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            r.push_back(prices[i + 1] - prices[i]);
        }
        return find_max_sum(r);
    }
    int find_max_sum(vector<int> &r)
    {
        auto sum = 0;
        auto max_sum = 0;
        for (int i = 0; i < r.size(); i++)
        {
            sum += r[i];
            if (sum < 0)
                sum = 0;
            else
                max_sum = max(sum, max_sum);
        }
        return max_sum;
    }
};
