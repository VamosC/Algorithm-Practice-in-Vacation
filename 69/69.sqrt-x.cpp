/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */
class Solution
{
public:
    int mySqrt(int x)
    {
        // 牛顿迭代法
        // <=> 求 f(x) = x^2 - n 的近似解
        // 计算迭代公式 即经过当前x的横坐标对应的曲线上的点的切线与x轴的交点
        // f(x) = f'(xi)(x - xi) + f(xi)
        // 令f(x) = 0
        // x = xi - f(xi)/f'(xi)
        // 这里f'(x) = 2x
        // x = xi - (xi^2 - n)/(2xi) = xi/2 + n/(2xi) = (xi + n/xi) / 2
        double res = 1.0;
        double last = 0.0;
        while(last - res > 0.1 || last - res < 0)
        {
            last = res;
            res = (res + x/res) / 2;
        } 
        return static_cast<int>(res);
    }
};
