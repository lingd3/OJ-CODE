/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/unique-characters
@Language: C++
@Datetime: 17-04-10 11:38
*/

class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        // write your code here
        int size = str.size();
        for (int i = 0; i < size-1; i++) {
            for (int j = i+1; j < size; j++) {
                if (str[i] > str[j]) {
                    char temp = str[i];
                    str[i] = str[j];
                    str[j] = temp;
                }
            }
        }
        bool h = true;
        for (int i = 0; i < size-1; i++) {
            if (str[i] == str[i+1]) {
                h = false;
                break;
            }
        }
        return h;
    }
};