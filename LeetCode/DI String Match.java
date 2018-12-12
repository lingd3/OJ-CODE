class Solution {
    public int[] diStringMatch(String S) {
        int len = S.length();
        int[] rtn = new int[len+1];
		int max = len, min = 0, k = 0;
        for (int i = 0; i < len-1; i++) {
        	if (S.charAt(i) == 'I') {
        		rtn[k++] = min;
        		min++;
        	}
        	else {
        		rtn[k++] = max;
        		max--;
        	}
        }
        if (S.charAt(len-1) == 'I') {
            rtn[k++] = min;
            rtn[k] = max;
        }
        else {
            rtn[k++] = max;
            rtn[k] = min;
        }
		return rtn;
    }
}