/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/valid-parentheses
@Language: C++
@Datetime: 16-09-12 12:56
*/

class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        if (s == "") return true;
        stack<char> a;
        for(int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') a.push(s[i]);
            else if (s[i] == ')') {
                if (a.top() == '(') a.pop();
                else return false;
            }
            else if (s[i] == ']') {
                if (a.top() == '[') a.pop();
                else return false;
            }
            else if (s[i] == '}') {
                if (a.top() == '{') a.pop();
                else return false;
            }
        }
        if (a.empty()) return true;
        return false;
    }
};