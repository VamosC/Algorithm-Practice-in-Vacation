/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int rightmost = 0;
        int pos = 0;
        if (nums.size() == 1)
            return true;
        while (true)
        {
            int tmp_rightmost = -1;
            for (int i = pos; i <= rightmost; i++)
            {
                if (nums[i] + i > tmp_rightmost)
                {
                    pos = i;
                    tmp_rightmost = nums[i] + i;
                }
            }
            if (rightmost == tmp_rightmost)
                return false;
            rightmost = tmp_rightmost;
            if (rightmost >= nums.size() - 1)
                break;
        }
        return true;
    }
};
// @lc code=end
