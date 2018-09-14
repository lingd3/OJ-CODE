class Solution {
	public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) return "";
		String s = strs[0];
        for (int i = 1; i < strs.length; i++) {
        	StringBuilder sb = new StringBuilder();
        	String s1 = strs[i];
        	for (int j = 0; j < s.length() && j < s1.length(); j++) {
        		if (s.charAt(j) == s1.charAt(j)) {
        			sb.append(s.charAt(j));
        		}
        		else break;
        	}
        	s = sb.toString();
        	if (s.equals("")) return "";
        }
        return s;
    }
}