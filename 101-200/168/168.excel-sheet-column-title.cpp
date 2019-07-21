/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */
class Solution
{
public:
    string convertToTitle(int n)
    {
        string res = "";
        static unordered_map<int, string> table = {
            {1, "A"},
            {2, "B"},
            {3, "C"},
            {4, "D"},
            {5, "E"},
            {6, "F"},
            {7, "G"},
            {8, "H"},
            {9, "I"},
            {10, "J"},
            {11, "K"},
            {12, "L"},
            {13, "M"},
            {14, "N"},
            {15, "O"},
            {16, "P"},
            {17, "Q"},
            {18, "R"},
            {19, "S"},
            {20, "T"},
            {21, "U"},
            {22, "V"},
            {23, "W"},
            {24, "X"},
            {25, "Y"},
            {0, "Z"}};
        if (n == 26)
            return "Z";
        while (n > 0)
        {
            res.insert(0, table[n % 26]);
            if (n % 26 == 0)
            {
                n /= 26;
                n -= 1;
            }
            else
            {
                n /= 26;
            }
        }
        return res;
    }
};
