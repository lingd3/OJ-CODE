class Solution {
	public String addBinary(String a, String b) {
		char[] aa = a.toCharArray();
		char[] bb = b.toCharArray();
		int n = a.length() > b.length()? b.length(): a.length();
		List<Integer> list = new ArrayList<>();
		int carry = 0;
		for (int i = 0; i < n; i++) {
			int c1 = aa[a.length()-1-i]-'0';
			int c2 = bb[b.length()-1-i]-'0';
			if (c1+c2+carry < 2) {
				list.add(c1+c2+carry);
				carry = 0;
			}
			else {
				list.add(c1+c2+carry-2);
				carry = 1;
			}
		}
		if (a.length() > b.length()) {
			for (int i = a.length()-1-n; i >= 0; i--) {
				int c1 = aa[i]-'0';
				if (c1+carry < 2) {
					list.add(c1+carry);
					carry = 0;
				}
				else {
					list.add(c1+carry-2);
					carry = 1;
				}
			}
		}
		else {
			for (int i = b.length()-1-n; i >= 0; i--) {
				int c1 = bb[i]-'0';
				if (c1+carry < 2) {
					list.add(c1+carry);
					carry = 0;
				}
				else {
					list.add(c1+carry-2);
					carry = 1;
				}
			}
		}
		if (carry == 1) {
			list.add(1);
		}
        StringBuilder sb = new StringBuilder();
        for (Integer i : list) {
        	sb.append(i);
        }
		return sb.reverse().toString();
    }
}