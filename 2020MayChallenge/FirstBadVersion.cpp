// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
auto static _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    int firstBadVersion(int n) {
        int i = 1;
        int j = n;
        int mid = 0;
        bool stop = false;
        while(i < j)
        {
            mid = i + (j-i)/2;
            if(isBadVersion(mid))
                j = mid;
            else
                i = mid+1;
        }
        
        return j;
    }
};
