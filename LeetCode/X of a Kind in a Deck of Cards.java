class Solution {
	public boolean hasGroupsSizeX(int[] deck) {
        int[] d = new int[10000];
        for (int i = 0; i < deck.length; i++) d[deck[i]]++;
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < 10000; i++) {
        		if (d[i] != 0) list.add(d[i]);
        }
        list.sort(new Comparator<Integer>() {
			@Override
			public int compare(Integer o1, Integer o2) {
				return o1-o2;
			}
		});
        int l = list.get(0);
		for (int i = 2; i <= l; i++) {
			boolean b = true;
			for (Integer ii : list) {
				if (ii%i != 0) {
					b = false;
					break;
				}
			}
			if (b == true) return true;
		}
		return false;
    }
}