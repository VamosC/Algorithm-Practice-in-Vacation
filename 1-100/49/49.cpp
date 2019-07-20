class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res;
        vector<vector<int>> pattern;
        for (auto str : strs)
        {
            auto flag = false;
            if (res.empty())
            {
                res.push_back(vector<string>{str});
                pattern.push_back(move(bucket(str)));
            }
            else
            {
                auto tmp = move(bucket(str));
                for (auto i = 0; i < pattern.size(); i++)
                {
                    if (compare(pattern[i], tmp))
                    {
                        res[i].push_back(str);
                        flag = true;
                        break;
                    }
                }
                if (flag)
                    continue;
                res.push_back(vector<string>{str});
                pattern.push_back(tmp);
            }
        }
        return res;
    }
    bool compare(vector<int> const &v1, vector<int> const &v2)
    {
        for (auto i = 0; i < 26; i++)
        {
            if (v1[i] != v2[i])
                return false;
        }
        return true;
    }
    vector<int> bucket(string const &str)
    {
        vector<int> res(26);
        for (auto c : str)
            res[c - 'a']++;
        return res;
    }
};