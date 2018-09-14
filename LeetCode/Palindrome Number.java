class Solution {
	public boolean isPalindrome(int x) {
		String s = String.valueOf(x);
		StringBuilder sb = new StringBuilder(s);
		sb = sb.reverse();
		return s.equals(sb.toString());
    }
}