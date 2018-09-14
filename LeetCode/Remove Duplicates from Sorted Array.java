class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length <= 1) return nums.length;
		int i = 0, len = nums.length;
		for (int j = 1; j < len; j++) {
			if (nums[i] < nums[j]) {
                nums[i+1] = nums[j];
				i++;
			}
		}
		return i+1;
    }
}