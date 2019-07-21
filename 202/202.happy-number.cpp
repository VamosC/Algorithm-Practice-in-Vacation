/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */
class Solution
{
public:
    bool isHappy(int n)
    {
        auto slow = n;
        auto fast = cal_num(n);
        if (slow == 1 || fast == 1)
            return true;
        while (slow != fast)
        {
            slow = cal_num(slow);
            fast = cal_num(cal_num(fast));
            if (slow == 1 || fast == 1)
                return true;
        }
        return false;
    }
    int cal_num(int x)
    {
        auto res = 0;
        while (x != 0)
        {
            res += pow(x % 10, 2);
            x /= 10;
        }
        return res;
    }
};
