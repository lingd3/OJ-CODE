class Solution {
public:
    //栈
    bool isValid(string s) {
        if (s[0] == ')' || s[0] == ']' || s[0] == '}') return false;
        stack<char> a;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') a.push(s[i]);
            else if (s[i] == ')') {
                if (!a.empty() && a.top() == '(') a.pop();
                else return false;
            }
            else if (s[i] == ']') {
                if (!a.empty() && a.top() == '[') a.pop();
                else return false;
            }
            else if (s[i] == '}') {
                if (!a.empty() && a.top() == '{') a.pop();
                else return false;
            }
        }
        if (!a.empty()) return false;
        return true;
    }
};