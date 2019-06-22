class Solution {
	public String mostCommonWord(String paragraph, String[] banned) {
        String rtn = "";
		StringBuffer sb = new StringBuffer();
		for (int i = 0; i < paragraph.length(); i++) {
			char c = paragraph.charAt(i);
			if (c == ' ' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') sb.append(c);
            else sb.append(' ');
		}
		String pa = sb.toString().toLowerCase();
		String[] strs = pa.split("\\s+");
		Map<String, Integer> map = new HashMap<>();
		for (int i = 0; i < strs.length; i++) {
			String s = strs[i];
			if (map.containsKey(s)) {
				int c = map.get(s);
				map.put(s, c+1);
			}
			else map.put(s, 1);
		}
		int max = -1;
		for (String key : map.keySet()) {
            System.out.println(key+" "+map.get(key));
			int i = 0;
			for (i = 0; i < banned.length; i++) {
				if (banned[i].equals(key)) break;
			}
			if (i < banned.length) continue;
			int count = map.get(key);
			if (count > max) {
				max = count;
				rtn = key;
			}
		}
		return rtn;
    }
}