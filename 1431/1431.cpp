auto static _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_val = 0;
        for(auto v : candies)
            max_val = max(max_val, v);
        vector<bool> res;
        for(auto v : candies)
            res.push_back(v + extraCandies >= max_val);
        return res;
    }
};
