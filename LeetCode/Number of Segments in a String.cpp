class Solution {
public:
    int countSegments(string s) {
        if (s == "") return 0;
        int count = 0, i;
        for (i = 0; i < s.size(); i++) {
            if (s[i] == ' ') continue;
            else break;
        }
        for (; i < s.size(); i++) {
            if (s[i] == ' ' && s[i-1] != ' ') count++;
        }
        if (s[s.size()-1] == ' ') count--;
        return count+1;
    }
};