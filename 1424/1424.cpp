auto static _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
	public:
		vector<int> findDiagonalOrder(vector<vector<int>>& nums)
		{
			vector<int> v;
            map<int, int, greater<int>> mp;
            int max_iter = max_length(nums);
            
            for(int k = 0; k < 2*max_iter-1; k++)
            {
                if(mp.empty() && k >= nums.size())
                    break;
                if(k < nums.size())
                    v.push_back(nums[k][0]);
                for(auto iter = mp.begin(); iter != mp.end();)
                {
                    v.push_back(nums[iter->first][iter->second]);
                    if(iter->second+1 < nums[iter->first].size())
                    {
                        (iter->second)++;
                        iter++;
                    }
                    else
                        mp.erase(iter++);
                }
                if(k < nums.size() && nums[k].size() > 1)
                    mp[k] = 1;
            }
            
			return v;
		}
	
	private:
	    int max_length(const vector<vector<int>>& v)
		{
			int max_size = v.size();

			for(int i = 0; i < v.size(); i++)
			{
				if(v[i].size() > max_size)
					max_size = v[i].size();
			}

			return max_size;
		}

};
