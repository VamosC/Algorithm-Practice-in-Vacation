class Solution {
    public boolean isAnagram(String s, String t) {
        int[] A = new int[26];
        int i;
        for(i = 0; i < s.length(); i++)
            A[s.charAt(i)-'a']++;
        for(i = 0; i < t.length(); i++)
            A[t.charAt(i)-'a']--;
        for(i = 0; i < 26; i++)
            if(A[i] != 0)
                break;
        if(i < 26)
            return false;
        else
            return true;
    }
}
