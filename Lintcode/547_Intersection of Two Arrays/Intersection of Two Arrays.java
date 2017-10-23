public class Solution {
	/**
	 * @param nums1
	 *            an integer array
	 * @param nums2
	 *            an integer array
	 * @return an integer array
	 */
	public int[] intersection(int[] nums1, int[] nums2) {
		Set<Integer> s1 = new HashSet<Integer>();
		Set<Integer> s2 = new HashSet<Integer>();
		for (int i : nums1) {
			s1.add(i);
		}
		for (int i : nums2) {
			if (s1.contains(i)) {
				s2.add(i);
			}
		}
		Object[] o = s2.toArray();
		int[] r = new int[s2.size()];
		for (int i = 0; i < o.length; i++) {
			r[i] = (int) o[i];
		}
		return r;
	}
}