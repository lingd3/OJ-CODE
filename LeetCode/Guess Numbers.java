class Solution {
    public int game(int[] guess, int[] answer) {
        int sum = 0;
        for (int i = 0; i < guess.length; i++) {
            if (guess[i] == answer[i]) sum++;
        }
        return sum;
    }
}