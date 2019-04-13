class Solution {
	public int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        long low = 0, high = x;
        while (low <= high) {
        	long mid = (low+high)/2;
        	if (mid*mid <= x && (mid+1)*(mid+1) > x) return (int) mid;
        	if (mid*mid > x) high = mid-1;
        	else if (mid*mid < x) low = mid+1;
        }
		return (int) low;
    }
}