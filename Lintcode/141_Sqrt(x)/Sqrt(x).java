public class Solution {
	/*
	 * @param x: An integer
	 * 
	 * @return: The sqrt of x
	 */
	public int sqrt(int x) {
		if (x == 0 || x == 1)
			return x;
		int left = 0, right = x;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			long s1 = (long) mid * (long) mid;
			long s2 = (long) (mid + 1) * (long) (mid + 1);
			long s3 = (long) (mid - 1) * (long) (mid - 1);

			if (s1 == x)
				return mid;
			if (s1 < x && s2 > x)
				return mid;
			if (s1 > x && s3 < x)
				return mid - 1;
			if (s1 < x)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return -1;
	}

}