class Solution
{
public:
    int reverse(int x)
    {
        if (x == INT_MAX || x == INT_MIN)
            return 0;
        uint64_t result = 0;
        bool neg = x < 0;
        if (neg)
            x = -x;
        while (x > 0)
        {
            result *= 10;
            result += x % 10;
            x /= 10;
        }
        return ((neg && -result < INT_MIN) || (!neg && result > INT_MAX)) ? 0 : (neg ? static_cast<int>(-result) : static_cast<int>(result));
    }
};