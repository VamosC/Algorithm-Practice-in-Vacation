/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        auto flag = false;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits[i] == 9)
            {
                digits[i] = 0;
                flag = true;
            }
            else
            {
                digits[i]++;
                flag = false;
                break;
            }
        }
        if (flag)
        {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
