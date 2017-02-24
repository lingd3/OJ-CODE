class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s == "" && t == "" || s.size() == 1 && t.size() == 1) return true;
        if (s.size() != t.size()) return false;
        char a[500] = {'\0'};
        for (int i = 0; i < 500; i++) a[i] = ' ';
        int i;
        for (i = 0; i < s.size(); i++) {
            if (a[s[i]] == ' ') a[s[i]] = t[i];
            else if (a[s[i]] == t[i]) continue;
            else break;
        }
        if (i != s.size()) return false;
        for (int i = 0; i < 500; i++) a[i] = ' ';
        for (i = 0; i < t.size(); i++) {
            if (a[t[i]] == ' ') a[t[i]] = s[i];
            else if (a[t[i]] == s[i]) continue;
            else break;
        }
        if (i != s.size()) return false;
        return true;
    }
};