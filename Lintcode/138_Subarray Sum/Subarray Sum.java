public class Solution {
	/**
	 * @param nums:
	 *            A list of integers
	 * @return: A list of integers includes the index of the first number and
	 *          the index of the last number
	 */
	public ArrayList<Integer> subarraySum(int[] nums) {
		ArrayList<Integer> list = new ArrayList<Integer>();
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		map.put(0, -1);
		int sum = 0;
		for (int i = 0; i < nums.length; i++) {
			if (map.containsKey(sum + nums[i])) {
				list.add(map.get(sum + nums[i]) + 1);
				list.add(i);
				break;
			} else {
				sum += nums[i];
				map.put(sum, i);
			}
		}
		return list;
	}

}