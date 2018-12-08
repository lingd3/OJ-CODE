public String reverseOnlyLetters(String S) {
        char[] cs = new char[S.length()];
        int len = 0;
		for (int i = 0; i < S.length(); i++) {
			char c = S.charAt(i);
			if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') cs[len++] = c;
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < S.length(); i++) {
			char c = S.charAt(i);
			if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') sb.append(cs[--len]);
			else sb.append(c);
		}
		return sb.toString();
    }