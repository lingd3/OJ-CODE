class Solution {
    public String reverseWords(String s) {
        String[] strs = s.split(" ");
        StringBuilder sb1 = new StringBuilder();
        StringBuilder sb = null;
        for (int i = 0; i < strs.length-1; i++) {
        	sb = new StringBuilder(strs[i]);
        	sb = sb.reverse();
        	sb1.append(sb+" ");
        }
        sb = new StringBuilder(strs[strs.length-1]);
        sb = sb.reverse();
        sb1.append(sb);
		return sb1.toString();
    }
}