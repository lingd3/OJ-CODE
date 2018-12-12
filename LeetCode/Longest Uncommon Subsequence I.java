class Solution {
    public int findLUSlength(String a, String b) {
		int l1 = a.length(), l2 = b.length();
        if (l1 != l2) return l1 > l2 ? l1 : l2;
		if (a.equals(b)) return -1;
		return l1;
    }
}