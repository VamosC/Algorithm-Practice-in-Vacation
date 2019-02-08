class Solution {
    public int findContentChildren(int[] g, int[] s) {
        int i, j;
        Arrays.sort(g);
        Arrays.sort(s);
        for(i = 0,j = 0; i < g.length && j < s.length; j++){
            if(s[j] >= g[i])
                i++;
        }
        return i;
    }
}
