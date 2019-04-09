class Solution {
	public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int count = 0, k = 0;
        for (int i = 0; i < s.length; i++) {
        	int a = s[i];
        	for (int j = k; j < g.length; j++) {
        		if (a >= g[j]) {
        			count++;
        			k = j+1;
        			break;
        		}
        	}
        }
		return count;
    }
}