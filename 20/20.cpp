class Solution
{
public:
    bool isValid(string s)
    {
        stack t;
        for (auto it : s)
        {
            if (it == '(' || it == '{' || it == '[')
                t.push(it);
            else if (it == ')')
            {
                if (t.empty())
                    return false;
                else if (t.pop() != '(')
                    return false;
            }
            else if (it == '}')
            {
                if (t.empty())
                    return false;
                else if (t.pop() != '{')
                    return false;
            }
            else if (it == ']')
            {
                if (t.empty())
                    return false;
                else if (t.pop() != '[')
                    return false;
            }
        }
        return t.empty();
    }
    class stack
    {
    private:
        vector<char> s;

    public:
        stack(/* args */) {}
        ~stack() {}
        bool empty()
        {
            return s.empty();
        }
        void push(char c)
        {
            s.push_back(c);
        }
        char pop()
        {
            auto c = s.back();
            s.pop_back();
            return c;
        }
    };
};