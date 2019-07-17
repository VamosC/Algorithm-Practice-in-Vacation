class Solution
{
public:
    bool isPalindrome(int x)
    {
        return x < 0 ? false : x == reverse(x);
    }
    int reverse(int x)
    {
        int64_t result = 0;
        while (x % 10 != x)
        {
            result *= 10;
            result += x % 10;
            x /= 10;
        }
        result *= 10;
        result += x % 10;
        return ((result < INT_MIN) || (result > INT_MAX)) ? 0 : static_cast<int>(result);
    }
};