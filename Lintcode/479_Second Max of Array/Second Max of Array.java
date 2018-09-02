public class Solution {
    /**
     * @param nums: An integer array
     * @return: The second max number in the array.
     */
    public int secondMax(int[] nums) {
        // write your code here
		int max1 = nums[0], max2 = nums[1];
		if (max1 < max2) {
			int temp = max1;
			max1 = max2;
			max2 = temp;
		}
		for (int i = 2; i < nums.length; i++) {
			if (nums[i] < max2) continue;
			if (nums[i] >= max2 && nums[i] < max1) max2 = nums[i];
			else {
				int temp = max1;
				max1 = nums[i];
				max2 = temp;
			}
		}
		return max2;
    }
}