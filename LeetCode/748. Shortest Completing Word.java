class Solution {
	public String shortestCompletingWord(String licensePlate, String[] words) {
        int[] word = new int[26];
		String rtn = "";
        for (int i = 0; i < licensePlate.length(); i++) {
			char c = licensePlate.charAt(i);
			if (c >= 'a' && c <= 'z') word[c-'a']++;
			else if (c >= 'A' && c <= 'Z') word[c-'A']++;
			else continue;
		}
		for (int i = 0; i < words.length; i++) {
			int[] temp = new int[26];
			String s = words[i];
			for (int j = 0; j < s.length(); j++) {
				char c = s.charAt(j);
				if (c >= 'a' && c <= 'z') temp[c-'a']++;
				else if (c >= 'A' && c <= 'Z') temp[c-'A']++;
			}
			int j = 0;
			for (j = 0; j < 26; j++) {
				if (word[j] <= temp[j]) continue;
				else break;
			}
            if (j == 26 && rtn.length() == 0) rtn = s;
			else if (j == 26 && rtn.length() > s.length()) rtn = s;
		}
		return rtn;
    }
}