class Solution {
	public static List<String> commonChars(String[] A) {
		List<String> list = new ArrayList<>();
		String[] rtn = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
		int[][] a = new int[A.length][26];
		for (int i = 0; i < A.length; i++) {
			for (int j = 0; j < A[i].length(); j++) {
				int t = A[i].charAt(j)-'a';
				a[i][t]++;
			}
		}
		
		for (int i = 0; i < 26; i++) {
			int min = a[0][i];
			for (int j = 1; j < a.length; j++) {
				if (min > a[j][i]) min = a[j][i];
			}
			for (int j = 0; j < min; j++) list.add(rtn[i]);
		}
		return list;
    }
}