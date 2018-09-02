public class Solution {
    /**
     * @param number: A 3-digit number.
     * @return: Reversed number.
     */
    public int reverseInteger(int number) {
        // write your code here
        StringBuilder sb = new StringBuilder(String.valueOf(number));
        String num = sb.reverse().toString();
        return Integer.valueOf(num);
    }
    
}