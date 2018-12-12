class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        for (int i = 0; i < words.length-1; i++) {
        	int l1 = words[i].length();
        	int l2 = words[i+1].length();
        	int temp = 0;
        	for (int j = 0; j < l1 && j < l2; j++) {
        		int index1 = order.indexOf(words[i].charAt(j));
        		int index2 = order.indexOf(words[i+1].charAt(j));
        		if (index1 > index2) return false;
        		if (index1 < index2) {
        			temp = 1;
        			break;
        		}
        		else continue;
        	}
        	if (temp == 0 && l1 > l2) return false;
        }
		return true;
    }
}