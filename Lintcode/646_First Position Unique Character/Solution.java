public class Solution {
    /**
     * @param s a string
     * @return it's index
     */
    public int firstUniqChar(String s) {
    	int[] a = new int[256];
    	for (int i = 0; i < 256; i++) a[i] = 0;
    	for (int i = 0; i < s.length(); i++) {
    		a[s.charAt(i)]++;
    	}
    	for (int i = 0; i < s.length(); i++) {
    		if (a[s.charAt(i)] == 1) return i;
    	}
    	return -1;
    }
}