class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
		List<Integer> list = new ArrayList<>();
		for (int i = left; i <= right; i++) {
			if (isDivisible(i)) list.add(i);
		}
		return list;
    }

	private boolean isDivisible(int n) {
		String s = String.valueOf(n);
		for (int i = 0; i < s.length(); i++) {
			int t = s.charAt(i)-'0';
			if (t == 0) return false;
			if (n%t != 0) return false;
		}
		return true;
	}
}