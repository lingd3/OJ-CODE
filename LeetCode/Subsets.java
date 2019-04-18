class Solution {
	public List<List<Integer>> subsets(int[] nums) {
		List<List<Integer>> rtn = new ArrayList<>();
		for (int i = nums.length-1; i >= 0; i--) {
			List<List<Integer>> rtn2 = new ArrayList<>();
			int t = nums[i];
			for (List<Integer> l : rtn) {
				List<Integer> l2 = new ArrayList<>();
				l2.addAll(l);
				l2.add(t);
				rtn2.add(l2);
                rtn2.add(l);
			}
			List<Integer> l2 = new ArrayList<>();
			l2.add(t);
            rtn2.add(l2);
            rtn = rtn2;
		}
		rtn.add(new ArrayList<>());
		return rtn;
    }
}