class Solution {
	public boolean isOneBitCharacter(int[] bits) {
        if (bits.length == 1 && bits[0] == 0) return true;
        int len = bits.length;
        if (bits[len-1] == 1) return false;
        int count = 0;
        for (int i = len-2; i >= 0; i--) {
        	if (bits[i] == 1) {
        		count++;
        		continue;
        	}
        	else break;
        }
        if (count%2 == 0) return true;
        return false;
    }
}