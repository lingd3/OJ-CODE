class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
		List<String> list = new ArrayList<>();
		HashMap<String, Integer> map = new HashMap<>();
		for (int i = 0; i < cpdomains.length; i++) {
			String[] strs = cpdomains[i].split(" ");
			int num = Integer.parseInt(strs[0]);
			String[] domains = strs[1].split("\\.");
			String key = "";
			for (int j = domains.length-1; j >= 0; j--) {
				if (j == domains.length-1) key = domains[domains.length-1];
				else key = domains[j]+"."+key;
				if (map.containsKey(key)) {
					int oldNum = map.get(key);
					map.put(key, num+oldNum);
				}
				else map.put(key, num);
			}
		}
		Set<String> s = map.keySet();
		for (String key : s) {
			String a = map.get(key) + " " + key;
			list.add(a);
		}
		return list;
    }
}