auto static _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    int findComplement(int num) {
        int n = floor(log2(num*1.))+1;
        return pow(2, n) - num - 1;
    }
};
