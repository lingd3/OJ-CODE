class Solution {
    public int numRookCaptures(char[][] board) {
    	int len = board.length;
    	int Rx = 0, Ry = 0;
    	int count = 0;
        // 先找R的位置
    	for (int i = 0; i < len; i++) {
        	for (int j = 0; j < len; j++) {
        		if (board[i][j] == 'R') {
        			Rx = i;
        			Ry = j;
        			break;
        		}
        	}
        }
    	// 往四个方向走
    	for (int i = Rx-1; i >= 0; i--) {
    		if (board[i][Ry] == 'B') break;
    		if (board[i][Ry] == 'p') {
    			count++;
    			break;
    		}
    	}
    	for (int i = Rx+1; i < len; i++) {
    		if (board[i][Ry] == 'B') break;
    		if (board[i][Ry] == 'p') {
    			count++;
    			break;
    		}
    	}
    	for (int j = Ry-1; j >= 0; j--) {
    		if (board[Rx][j] == 'B') break;
    		if (board[Rx][j] == 'p') {
    			count++;
    			break;
    		}
    	}
    	for (int j = Ry+1; j < len; j++) {
    		if (board[Rx][j] == 'B') break;
    		if (board[Rx][j] == 'p') {
    			count++;
    			break;
    		}
    	}
    	return count;
    }
}