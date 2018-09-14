class Solution {
    public int numJewelsInStones(String J, String S) {
		int num = 0;
        for (int i = 0; i < S.length(); i++) {
        	if (J.contains(S.substring(i, i+1))) num++;
        }
		return num;
    }
}