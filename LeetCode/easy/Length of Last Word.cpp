class Solution {
public:
    int lengthOfLastWord(string s) {
        while (s != "" && s.find_last_of(' ') == s.size()-1) {
            s.replace(s.find_last_of(' '), 1, "");
        }
        if (s == "") return 0;
        int i = s.find_last_of(' ');
        if (i == -1) return s.size();
        return s.size()-i-1;
    }
};