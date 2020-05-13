auto static _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> tb;
        for(auto ch : J)
        {
            tb.insert(ch);
        }
        int count = 0;
        for(auto ch : S)
        {
            if(tb.count(ch) != 0)
                count++;
        }
        return count;
    }
};
