public class Solution {
	/**
	 * @param strs:
	 *            A list of strings
	 * @return: A list of strings
	 */
	public List<String> anagrams(String[] strs) {
		Map<Integer, String> map = new HashMap<>();
		int len = strs.length;
		for (int i = 0; i < len; i++) {
			String s = strs[i];
			char[] temp = s.toCharArray();
			Arrays.sort(temp);
			map.put(i, String.valueOf(temp));
		}

		int[] visited = new int[len];
		for (int i = 0; i < len; i++) {
			visited[i] = 0;
		}

		List<String> list = new ArrayList<>();
		for (int i = 0; i < len; i++) {
			String a = map.get(i);
			if (visited[i] == 1)
				continue;
			for (int j = i + 1; j < len; j++) {
				if (visited[j] == 1)
					continue;
				String b = map.get(j);
				if (a.equals(b)) {
					if (!list.contains(strs[i]))
						list.add(strs[i]);
					list.add(strs[j]);
					visited[j] = 1;
				}
			}
		}
		return list;
	}
}