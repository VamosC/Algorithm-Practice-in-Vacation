/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */
class MyStack
{
private:
    deque<int> s;
    deque<int> h;

public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        if (h.empty())
            s.push_back(x);
        else
            h.push_back(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        auto tmp = 0;
        if (h.empty())
        {
            while (s.size() != 1)
            {
                h.push_back(s[0]);
                s.pop_front();
            }
            tmp = s[0];
            s.pop_front();
        }
        else
        {
            while (h.size() != 1)
            {
                s.push_back(h[0]);
                h.pop_front();
            }
            tmp = h[0];
            h.pop_front();
        }
        return tmp;
    }

    /** Get the top element. */
    int top()
    {
        if (s.empty())
            return h[h.size() - 1];
        else
            return s[s.size() - 1];
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return s.empty() && h.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
