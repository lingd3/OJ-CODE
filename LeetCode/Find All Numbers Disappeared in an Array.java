class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
		List<Integer> list = new ArrayList<>();
		for (int i = 0; i < nums.length; i++) {
			int v = nums[i];
			if (v == i+1) continue;
			else {
				if (nums[v-1] == v) continue;
				int temp = nums[v-1];
				nums[v-1] = v;
				nums[i] = temp;
				if (nums[i] == i+1) continue;
				else i--;
			}
		}
		for (int i = 0; i < nums.length; i++) {
			if (nums[i] != i+1) list.add(i+1);
		}
		return list;
    }
}