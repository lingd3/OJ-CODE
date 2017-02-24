class Solution {
public:
    string reverseVowels(string s) {
        for (int i = 0, j = s.size()-1; i < j;) {
            if (!(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')) {
                i++;
                continue;
            }
            if (!(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' || s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U')) {
                j--;
                continue;
            }
            char b = s[i];
            char c = s[j];
            s.replace(i, 1, 1, c);
            s.replace(j, 1, 1, b);
            i++;
            j--;
        }
        return s;
    }
};