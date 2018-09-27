class Solution {
    public int[] shortestToChar(String S, char C) {
        int[] rtn = new int[S.length()];
		for (int i = 0; i < S.length(); i++) {
			if (S.charAt(i) == C) {
				rtn[i] = 0;
				continue;
			}
			int min = S.length();
			for (int j = 0; j < S.length(); j++) {
				if (i == j) continue;
				if (S.charAt(j) == C) {
					if (min > Math.abs(i-j)) min = Math.abs(i-j);
				}
			}
			rtn[i] = min;
		}
        return rtn;
    }
}