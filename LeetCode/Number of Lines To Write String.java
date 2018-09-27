class Solution {
    public int[] numberOfLines(int[] widths, String S) {
        int[] rtn = new int[2];
        int lines = 1, count = 0;
        for (int i = 0; i < S.length(); i++) {
        	int t = (int)S.charAt(i)-97;
        	if (count+widths[t] > 100) {
        		lines++;
        		count = widths[t];
        	}
        	else {
        		count += widths[t];
        	}
        }
        rtn[0] = lines;
		rtn[1] = count;
		return rtn;
    }
}