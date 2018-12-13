class Solution {
    public String toGoatLatin(String S) {
		String[] s = S.split(" ");
		for (int i = 0; i < s.length; i++) {
			char c = s[i].charAt(0);
			String a = s[i];
			if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U') {
				s[i] = a+"ma";
			}
			else {
				s[i] = a.substring(1)+a.charAt(0)+"ma";
			}
			a = "";
			for (int j = 0; j <= i; j++) {
				a += "a";
			}
			s[i] += a;
		}
		String rtn = "";
		for (int i = 0; i < s.length-1; i++) {
			rtn += s[i] + " ";
		}
		rtn += s[s.length-1];
		return rtn;
    }
}