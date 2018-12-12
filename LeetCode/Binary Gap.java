class Solution {
    public int binaryGap(int N) {
        String n = Integer.toBinaryString(N);
		int a = 0, max = -1;
        for (int i = 1; i < n.length(); i++) {
			if (n.charAt(i) == '1') {
				if (i-a > max) max = i-a;
				a = i;
			}
		}
        if (max == -1) return 0;
		return max;
    }
}