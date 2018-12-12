class Solution {
    private boolean isPrime(int n) {
		if (n <= 1) return false;
		if (n == 2 || n == 3) return true;
		for (int i = 2; i < n/2+1; i++) {
			if (n%i == 0) return false;
		}
		return true;
	}
	
	public int countPrimeSetBits(int L, int R) {
		int n = 0;
        for (int i = L; i <= R; i++) {
        	String s = Integer.toBinaryString(i);
        	int count = 0;
        	for (int j = 0; j < s.length(); j++) {
        		if (s.charAt(j) == '1') count++;
        	}
        	if (isPrime(count)) n++;
        }
		return n;
    }
}