class Solution {
	public String licenseKeyFormatting(String S, int K) {
		Queue<Character> q = new LinkedList<>();
		for (int i = 0; i < S.length(); i++) {
			char c = S.charAt(i);
			if (c == '-') continue;
			else q.add(c);
		}
		StringBuilder sb = new StringBuilder();
		int a = q.size()%K;
		if (a == 0) a = K;
		for (int i = 0; i < a; i++) {
			if (!q.isEmpty()) sb.append(q.poll());
		}
		a = 0;
		while (!q.isEmpty()) {
			if (a == 0) sb.append("-");
			sb.append(q.poll());
			a++;
            if (a == K) a = 0;
		}
		return sb.toString().toUpperCase();
    }
}