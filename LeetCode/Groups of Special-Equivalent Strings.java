public int numSpecialEquivGroups(String[] A) {
        Set<String> set = new HashSet<>();
        for (String s : A) {
        	String even = "", odd = "";
        	for (int i = 0; i < s.length(); i++) {
        		if (i%2 == 0) even += s.charAt(i);
        		else odd += s.charAt(i);
        	}
        	char[] evenArray = even.toCharArray();
        	Arrays.sort(evenArray);
        	even = String.copyValueOf(evenArray);
        	
        	char[] oddArray = odd.toCharArray();
        	Arrays.sort(oddArray);
        	odd = String.copyValueOf(oddArray);
        	
        	set.add(even+odd);
        	
        }
		return set.size();
    }