public class Solution {
	/*
	 * @param words: A list of words
	 * 
	 * @return: Return how many different rotate words
	 */
	public int countRotateWords(List<String> words) {
		int size = words.size();
		int[] visited = new int[size];
		for (int i = 0; i < size; i++) {
			visited[i] = 0;
		}
		int num = 0;
		for (int i = 0; i < size; i++) {
			if (visited[i] == 1)
				continue;
			num++;
			String left = words.get(i);
			for (int j = i + 1; j < size; j++) {
				if (visited[j] == 1)
					continue;
				String right = words.get(j);
				if (right.length() != left.length())
					continue;
				right = right.concat(right);
				if (right.contains(left)) {
					visited[j] = 1;
				}
			}
		}
		return num;
	}

}