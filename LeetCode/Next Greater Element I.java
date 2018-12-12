class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums2.length; i++) {
        	map.put(nums2[i], i);
        }
        int len = nums1.length, k = 0;
        int[] rtn = new int[len];
        for (int i = 0; i < len; i++) {
        	int index = map.get(nums1[i]);
        	int j;
        	for (j = index+1; j < nums2.length; j++) {
        		if (nums2[j] > nums1[i]) {
        			rtn[k++] = nums2[j];
        			break;
        		}
        	}
        	if (j == nums2.length) rtn[k++] = -1;
        }
        return rtn;
    }
}