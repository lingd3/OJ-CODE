class Solution {
	public int[] deckRevealedIncreasing(int[] deck) {
        int[] rtn = new int[deck.length];
        Arrays.sort(deck);
        Deque<Integer> q = new ArrayDeque<>();
        q.addLast(deck[deck.length-1]);
        for (int i = deck.length-2; i >= 0; i--) {
        	int t = q.pollLast();
        	q.addFirst(t);
        	q.addFirst(deck[i]);
        }
        int i = 0;
        while (!q.isEmpty()) {
        	rtn[i++] = q.pollFirst();
        }
        return rtn;
    }
}