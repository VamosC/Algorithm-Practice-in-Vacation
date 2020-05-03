auto static _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    string reformat(string s) {
        if(s.empty())
            return "";
        vector<char> digits;
        vector<char> alpha;
        for(auto ch : s)
        {
            if(is_digit(ch))
                digits.push_back(ch);
            else
                alpha.push_back(ch);
        }
        int size_diff = digits.size() - alpha.size();
        if((digits.empty() && alpha.empty()) || abs(size_diff) > 1)
            return "";
        if(digits.size() > alpha.size())
            return generate(digits, alpha);
        else
            return generate(alpha, digits);
    }
private:
    bool is_digit(char c) 
    {
        return c >= '0' && c <= '9';
    }
    string generate(vector<char>& a, vector<char> &b)
    {
        string s;
        for(int i = 0; i < b.size(); i++)
        {
            s += a[i];
            s += b[i];
        }
        if(a.size() != b.size())
            s += a.back();
        return s;
    }
};
