/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
auto static _ = []() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    return 0;
}();
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        set<char> s;
        for (auto row : board)
        {
            s.clear();
            for (auto num : row)
            {
                if (num == '.')
                    continue;
                if (s.count(num) != 0)
                    return false;
                s.insert(num);
            }
        }
        for (int i = 0; i < board[0].size(); i++)
        {
            s.clear();
            for (int j = 0; j < board.size(); j++)
            {
                if (board[j][i] == '.')
                    continue;
                if (s.count(board[j][i]) != 0)
                    return false;
                s.insert(board[j][i]);
            }
        }
        // s.clear();
        // for (int i = 0; i < board.size(); i++)
        // {
        //     if (board[i][i] == '.')
        //         continue;
        //     if (s.count(board[i][i]) != 0)
        //         return false;
        //     s.insert(board[i][i]);
        // }
        // s.clear();
        // for (int i = 0; i < board.size(); i++)
        // {
        //     if (board[i][8 - i] == '.')
        //         continue;
        //     if (s.count(board[i][8 - i]) != 0)
        //         return false;
        //     s.insert(board[i][8 - i]);
        // }
        for (int i = 1; i < board.size(); i += 3)
        {
            for (int j = 1; j < board.size(); j += 3)
            {
                s.clear();
                for (int m = -1; m <= 1; m++)
                {
                    for (int n = -1; n <= 1; n++)
                    {
                        if (board[i + m][j + n] == '.')
                            continue;
                        if (s.count(board[i + m][j + n]) != 0)
                            return false;
                        s.insert(board[i + m][j + n]);
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end
