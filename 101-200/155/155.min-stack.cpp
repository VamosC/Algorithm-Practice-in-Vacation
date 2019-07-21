/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */
class MinStack
{
private:
    vector<int> v;
    int minimum;

public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        minimum = v.empty() ? x : min(x, minimum);
        v.push_back(x);
    }

    void pop()
    {
        v.pop_back();
        minimum = INT_MAX;
        if (!v.empty())
        {
            for (auto it : v)
            {
                if (it < minimum)
                    minimum = it;
            }
        }
    }

    int top()
    {
        return v.back();
    }

    int getMin()
    {
        return minimum;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
