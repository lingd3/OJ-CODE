public class Solution {
    /*
     * @param n: the integer to be reversed
     * @return: the reversed integer
     */
    int reverseInteger(int n) {
            boolean fushu = false;
            if (n < 0) {
                    fushu = true;
                    n = -1*n;
            }
            String num = String.valueOf(n);
            StringBuilder sb = new StringBuilder(num);
            sb.reverse();
            num = sb.toString();
            try {
                    int output = Integer.valueOf(num);
                    if (fushu) {
                            output *= -1;
                    }
                    return output;
            } catch (Exception e) {
                        return 0;
                }
    }
}