#include <bits/stdc++.h>
using namespace std;
auto static _ = [](){
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
}();
class Solution {
public:
    int maxScore(string s) {
        vector<int> start;
        vector<int> end;
		int n_size = s.size();
		start.push_back(1 - (s.front() - '0'));
		end.push_back(s.back() - '0');
        for(int i = 1; i < n_size; i++)
        {
           start.push_back(start[i-1] + (1 - (s.at(i) - '0')));
		   end.push_back(end[i-1] + s.at(n_size-1-i) - '0');
        }
		int max_sum = 0;
		for(int i = 0; i < n_size-1; i++)
			max_sum = max(max_sum, start[i] + end[n_size - 2 - i]);
		return max_sum;
    }
};
