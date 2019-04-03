class Solution {
	public boolean checkPossibility(int[] nums) {
		int count = 1;
		int len = nums.length;
		for (int i = 1; i < len; i++) {
			if (nums[i] < nums[i-1]) {
				if (count == 0) return false;
				if (i == 1 || nums[i] >= nums[i-2]) nums[i-1] = nums[i];
				else nums[i] = nums[i-1];
				count--;
			}
		}
		return true;
    }

}