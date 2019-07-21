/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */
class MyQueue
{
    stack<int> s;

public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        s.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        stack<int> helper;
        while (!s.empty())
        {
            helper.push(move(s.top()));
            s.pop();
        }
        auto res = helper.top();
        helper.pop();
        while (!helper.empty())
        {
            s.push(move(helper.top()));
            helper.pop();
        }
        return res;
    }

    /** Get the front element. */
    int peek()
    {
        stack<int> helper;
        while (!s.empty())
        {
            helper.push(move(s.top()));
            s.pop();
        }
        auto res = helper.top();
        while (!helper.empty())
        {
            s.push(move(helper.top()));
            helper.pop();
        }
        return res;
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
