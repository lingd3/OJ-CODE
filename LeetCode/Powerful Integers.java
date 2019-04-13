class Solution {
	public List<Integer> powerfulIntegers(int x, int y, int bound) {
		List<Integer> list = new ArrayList<>();
		Set<Integer> s = new HashSet<>();
		if (x == 1 && y == 1) {
			if (bound < 2) return list;
			else {
				list.add(2);
				return list;
			}
		}
		if (x < y) {
			int temp = x;
			x = y;
			y = temp;
		}
		
		for (int i = 0; ; i++) {
			int a = (int) Math.pow(x, i);
			if (a > bound) break;
			if (y == 1) {
				int b = a+1;
				if (b > bound) break;
				else s.add(b);
			}
			else {
				for (int j = 0; ; j++) {
					int b = a+(int) Math.pow(y, j);
					if (b > bound) break;
					else s.add(b);
				}
			}
		}
		for (Integer i : s) {
			list.add(i);
		}
		return list;
    }
}