class Solution
{
public:
    double myPow(double x, int n)
    {
        if (x == 0)
            return 0;
        uint64_t exp = n;
        auto neg = n < 0;
        if (neg)
            exp = -exp;
        return neg ? 1 / powHelper(x, exp) : powHelper(x, exp);
    }
    double powHelper(double x, uint64_t n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        auto result = powHelper(x, n / 2);
        return n % 2 == 1 ? result * result * x : result * result;
    }
};