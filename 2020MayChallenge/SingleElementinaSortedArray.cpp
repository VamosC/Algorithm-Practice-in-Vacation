auto static _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = 0;
        for (auto v : nums)
        {
            res ^= v;
        }
        return res;
    }
};
