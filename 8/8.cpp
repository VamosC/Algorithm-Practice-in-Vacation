class Solution
{
public:
    int myAtoi(string str)
    {
        bool flag = false;
        bool neg = false;
        int sum = 0;
        for (auto it : str)
        {
            if (it == ' ')
            {
                if (flag)
                {
                    return neg ? -sum : sum;
                }
                continue;
            }
            if (it != '+' && it != '-' && (it < '0' || it > '9'))
            {
                if (!flag)
                {
                    return 0;
                }
                else
                {
                    return neg ? -sum : sum;
                }
            }
            if (it == '+')
            {
                if (!flag)
                {
                    flag = true;
                    continue;
                }
                else
                {
                    return neg ? -sum : sum;
                }
            }
            if (it == '-')
            {
                if (!flag)
                {
                    neg = true;
                    flag = true;
                    continue;
                }
                else
                {
                    return neg ? -sum : sum;
                }
            }
            flag = true;
            if (sum > INT_MAX / 10)
            {
                return neg ? INT_MIN : INT_MAX;
            }
            else if (sum == INT_MAX / 10)
            {
                if (neg)
                {
                    if ((it - '0') >= 8)
                    {
                        return INT_MIN;
                    }
                }
                else
                {
                    if ((it - '0') > 7)
                    {
                        return INT_MAX;
                    }
                }
            }
            sum *= 10;
            sum += (it - '0');
        }
        return neg ? -sum : sum;
    }
};
