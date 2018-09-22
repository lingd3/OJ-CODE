class Solution {
    public boolean judgeCircle(String moves) {
        int h = 0, v = 0;
        for (int i = 0; i < moves.length(); i++) {
        	char move = moves.charAt(i);
        	if (move == 'U') v++;
        	else if (move == 'D') v--;
        	else if (move == 'L') h--;
        	else h++;
        }
		if (h == 0 && v == 0) return true;
		return false;
    }
}