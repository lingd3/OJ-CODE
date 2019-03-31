class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> rtn = new ArrayList<>();
        Set<List<Integer>> set = new HashSet<>();
		perm(set, nums, 0, nums.length-1);
		for (List<Integer> list : set) {
			rtn.add(list);
		}
		return rtn;
    }

	
	void swap(int[] nums, int i, int j) {
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}
	
	void perm(Set<List<Integer>> rtn, int[] nums, int p, int q) {
		if (p == q) {
			List<Integer> list = new ArrayList<>();
			for (int i = 0; i < nums.length; i++) list.add(nums[i]);
			rtn.add(list);
		}
		else {
			for (int i = p; i <= q; i++) {
                if (i != p && nums[i] == nums[p]) continue;
				swap(nums, i, p);
				perm(rtn, nums, p+1, q);
				swap(nums, i, p);
			}
		}
	}
}