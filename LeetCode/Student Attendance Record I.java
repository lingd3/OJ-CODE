class Solution {
	public boolean checkRecord(String s) {
		int c1 = 0, c2 = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == 'A') c1++;
		}
        for (int i = 0; i < s.length()-2; i++) {
            if (s.charAt(i) == 'L' && s.charAt(i+1) == 'L' && s.charAt(i+2) == 'L') {
                c2 = 1;
                break;
            }
        }
		if (c1 <= 1 && c2 != 1) return true;
        return false;
    }
}