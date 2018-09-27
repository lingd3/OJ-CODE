class Solution {
    public String[] uncommonFromSentences(String A, String B) {
        Map<String, Integer> map = new HashMap<>();
        String[] As = A.split(" ");
        String[] Bs = B.split(" ");
        for (String s : As) {
        	if (map.containsKey(s)) {
        		int num = map.get(s);
        		map.put(s, num+1);
        	}
        	else map.put(s, 1);
        }
        for (String s : Bs) {
        	if (map.containsKey(s)) {
        		int num = map.get(s);
        		map.put(s, num+1);
        	}
        	else map.put(s, 1);
        }
        Set<String> keys = map.keySet();
        List<String> list = new ArrayList<>();
        for (String key : keys) {
        	if (map.get(key) == 1) list.add(key);
        }
        String[] rtn = new String[list.size()];
        list.toArray(rtn);
        return rtn;
    }
}