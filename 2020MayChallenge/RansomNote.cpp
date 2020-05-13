auto static _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> tb;
        bool flag = true;
        for(auto ch : magazine)
        {
            if(tb.count(ch) == 0)
                tb[ch] = 1;
            else
                tb[ch]++;
        }
        for(auto ch : ransomNote)
        {
            if(tb.count(ch) == 0 || tb[ch] == 0)
            {
                flag = false;
                break;
            }
            else
            {
                tb[ch]--;
            }
        }
        return flag;
    }
};
