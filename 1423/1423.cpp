auto static _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k)
	{
		vector<int> start;
		vector<int> end;
		int n_size = cardPoints.size();
		start.push_back(cardPoints.front());
		end.push_back(cardPoints.back());

		for(int i = 1; i < k; i++)
		{
			start.push_back(cardPoints[i]+start[i-1]);
			end.push_back(cardPoints[n_size-1-i]+end[i-1]);
		}

		int max_sum = max(start[k-1], end[k-1]);
		for(int i = 0; i < k-1; i++)
			max_sum = max(max_sum, start[i] + end[k-2-i]);

		return max_sum;
    }
};
