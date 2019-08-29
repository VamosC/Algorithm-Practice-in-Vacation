/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        if (nums.empty())
            return;
        auto size_ = nums.size();
        int i = 0;
        int j = 0;
        while (true)
        {
            while (i < size_ && nums[i] != 0)
                i++;
            if (i >= size_)
                return;
            j = i + 1;
            while (j < size_ && nums[j] == 0)
                j++;
            if (j >= size_)
                return;
            auto tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }
};
