class Solution {
    public boolean buddyStrings(String A, String B) {
        if (A.length() < 2 || B.length() < 2 || A.length() != B.length()) return false;
        int[] letters = new int[26];
        int diffCount = 0;
        for (int i = 0; i < A.length(); i++) {
            letters[(int)A.charAt(i)-97]++;
        	if (A.charAt(i) != B.charAt(i)) {
        		diffCount++;
        	}
        }
        if (diffCount == 2) {
        	char[] C = A.toCharArray(), D = B.toCharArray();
        	Arrays.sort(C);
        	Arrays.sort(D);
        	if (String.valueOf(C).equals(String.valueOf(D))) return true;
        	return false;
        }
        if (diffCount != 0) return false;
        for (int i = 0; i < 26; i++) {
        	if (letters[i] > 1) return true;
        }
        return false;
    }
}