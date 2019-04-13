class Solution {
	public boolean isLongPressedName(String name, String typed) {
        int a = 0, b = 0;
		while (a < name.length() && b < typed.length()) {
			int c = name.charAt(a);
			while (b < typed.length()) {
				if (typed.charAt(b) == c) break;
				else b++;
			}
            if (b == typed.length()) return false;
			a++;
			b++;
		}
		if (a == name.length()) return true;
		return false;
    }
}