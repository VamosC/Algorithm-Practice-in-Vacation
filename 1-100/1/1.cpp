class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> hash_map;
        for(auto i = 0; i < nums.size(); i++)
        {
        	if(hash_map.count(target - nums[i])) 
        	{
        		return std::vector<int>{hash_map[target - nums[i]], i};
        	} 
        	else 
        	{
        		hash_map[nums[i]] = i;
        	}
        }
        return std::vector<int>{};
    }
};