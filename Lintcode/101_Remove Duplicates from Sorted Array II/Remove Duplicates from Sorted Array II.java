package a;

public class Solution {
	/**
	 * @param A:
	 *            a array of integers
	 * @return : return an integer
	 */
	public int removeDuplicates(int[] nums) {
		int i = 0, count = 1;
		if (nums.length == 0)
			return 0;
		for (int j = 1; j < nums.length; j++) {
			if (nums[i] == nums[j] && count < 2) {
				count++;
				nums[++i] = nums[j];
			} else if (nums[j] != nums[i]) {
				count = 1;
				nums[++i] = nums[j];
			}
		}
		return i + 1;
	}

}