class Solution {
public:
    bool isAnagram(string s, string t) {
    	if(s.length() != t.length())
    		return false;
    	sort(s.begin(), s.end());
    	sort(t.begin(), t.end());
    	return s.compare(t) == 0 ? true : false;
    }
};