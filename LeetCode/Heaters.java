class Solution {
	public int findRadius(int[] houses, int[] heaters) {
		Arrays.sort(houses);
		Arrays.sort(heaters);
		int j = 0;
		int r = 0;
		for (int i = 0; i < houses.length; i++) {
			for (j = 0; j < heaters.length; j++) {
				if (heaters[j] >= houses[i]) break;  
			}
			if (j == 0) r = Math.max(r, heaters[j]-houses[i]);
			else if (j == heaters.length) return Math.max(r, houses[houses.length-1]-heaters[heaters.length-1]);
			else r = Math.max(r, Math.min(heaters[j]-houses[i], houses[i]-heaters[j-1]));
		}
		return r;
    }
}