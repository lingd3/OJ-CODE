	public List<Integer> getRow(int rowIndex) {
		List<Integer> list = new ArrayList<>(rowIndex+1);
		for (int i = 0; i <= rowIndex; i++) {
			for (int j = i-1; j > 0; j--) {
				list.set(j, list.get(j)+list.get(j-1));
			}
			list.add(1);
		}
		return list;
    }