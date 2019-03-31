class Solution {
	public boolean backspaceCompare(String S, String T) {
        Stack<Character> s1 = new Stack<>();
        Stack<Character> s2 = new Stack<>();
		for (int i = 0; i < S.length(); i++) {
			char c = S.charAt(i);
			if (c != '#') s1.push(c);
			else {
				if (!s1.isEmpty()) s1.pop();
			}
		}
		for (int i = 0; i < T.length(); i++) {
			char c = T.charAt(i);
			if (c != '#') s2.push(c);
			else {
				if (!s2.isEmpty()) s2.pop();
			}
		}
		StringBuilder sb1 = new StringBuilder();
		while (!s1.isEmpty()) {
			sb1.append(s1.pop());
		}
		StringBuilder sb2 = new StringBuilder();
		while (!s2.isEmpty()) {
			sb2.append(s2.pop());
		}
		if (sb1.toString().equals(sb2.toString())) return true;
		return false;
    }
}