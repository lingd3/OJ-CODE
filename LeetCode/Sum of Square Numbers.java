class Solution {
    public boolean judgeSquareSum(int c) {
        int q = (int) Math.sqrt(c);
        for (int i = 0; i < q+1; i++) {
            double t = c-i*i;
            int a = (int) Math.sqrt(t);
            if (a*a == t) return true;
            else continue;
        }
        return false;
    }
}