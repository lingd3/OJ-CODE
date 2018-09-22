class Solution {
    public String[] findWords(String[] words) {
        String a = "QWERTYUIOPqwertyuiop", b = "ASDFGHJKLasdfghjkl", c = "ZXCVBNMzxcvbnm";
        List<String> list = new LinkedList<>();
        for (int i = 0; i < words.length; i++) {
        	int t = 0, j = 0;
        	if (b.contains(words[i].substring(0, 1))) t = 1;
        	else if (c.contains(words[i].substring(0, 1))) t = 2;
        	for (j = 1; j < words[i].length(); j++) {
        		if (t == 0 && !a.contains(words[i].substring(j, j+1))) break;
        		if (t == 1 && !b.contains(words[i].substring(j, j+1))) break;
        		if (t == 2 && !c.contains(words[i].substring(j, j+1))) break;
        	}
        	if (j == words[i].length()) list.add(words[i]);
        }
        String[] rtn = new String[list.size()];
        for (int i = 0; i < list.size(); i++) {
        	rtn[i] = list.get(i);
        }
    	return rtn;
    }
}