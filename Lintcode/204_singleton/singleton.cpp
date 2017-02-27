/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/singleton
@Language: C++
@Datetime: 17-02-25 03:17
*/

class Solution {
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        static int exist = 0;
        static Solution* s;
        if (exist == 0) {
            s = new Solution();
            exist = 1;
            return s;
        }
        return s;
    }
};