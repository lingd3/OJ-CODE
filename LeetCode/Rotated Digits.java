	public boolean isValidAfterRotation(int n) {
		String a = String.valueOf(n);
		char[] nums = a.toCharArray();
		for (int i = 0; i < a.length(); i++) {
			if (nums[i] == '3' || nums[i] == '4' || nums[i] == '7') return false;
			if (nums[i] == '2') nums[i] = '5';
			else if (nums[i] == '5') nums[i] = '2';
			else if (nums[i] == '6') nums[i] = '9';
			else if (nums[i] == '9') nums[i] = '6';
		}
		String b = String.valueOf(nums);
		if (a.equals(b)) return false;
		return true;
	}
	
    public int rotatedDigits(int N) {
    	int num = 0;
    	for (int i = 2; i <= N; i++) {
    		if (isValidAfterRotation(i)) num++;
    	}
    	return num;
    }