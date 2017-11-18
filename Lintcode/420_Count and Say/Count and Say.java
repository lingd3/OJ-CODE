public class Solution {
    /*
     * @param n: the nth
     * @return: the nth sequence
     */
    public String countAndSay(int n) {
            String output = "";
            String input = "1";
            for (int i = 0; i < n-1; i++) {
                    int num = 0;
                    char temp;
                    for (int j = 0; j < input.length(); j++) {
                            num++;
                            temp = input.charAt(j); 
                            if (j < input.length()-1 && input.charAt(j+1) != temp || j == input.length()-1) {
                                    output += num;
                                    output += temp;
                                    num = 0;
                            }
                    }
                    input = output;
                    output = "";
            }
            return input;
    }
}