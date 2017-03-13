/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/reorder-array-to-construct-the-minimum-number
@Language: Java
@Datetime: 17-03-13 07:49
*/

public class Solution {
    /**
     * @param nums n non-negative integer array
     * @return a string
     */
    public String minNumber(int[] nums) {
        // Write your code here
        List<String> list = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            list.add(String.valueOf(nums[i]));
        }
        
        Collections.sort(list, new Comparator<String>() {
            public int compare(String s1, String s2) {
                int i = 0;
                for (i = 0; i < s1.length() && i < s2.length(); i++) {
                    if (s1.charAt(i) < s2.charAt(i)) return -1;
                    else if (s1.charAt(i) > s2.charAt(i)) return 1;
                }
                if (i == s1.length() && i == s2.length()) return 0;
                else {
                    if (i < s2.length()) return compare(s1, s2.substring(i));
                    else return compare(s1.substring(i), s2);
                }
            }
        });
        StringBuilder sb = new StringBuilder();
        for (String str:list) {
            sb.append(str);
        }
        String res=sb.toString();
        //去除前面的0
        int i = 0;
        while (res.charAt(i) == '0' && i < res.length()-1) {
            i++;
        }
        return res.substring(i);
    }
}






