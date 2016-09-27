class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        int count = 0;
        char b;
        string a = "1";
        n--;
        while (n--) {
            int length = a.size();
            string c = a;
            a = "";
            int i, j;
            for (i = 0; i < length; i++) {
                b = c[i];
                count = 1;
                for (j = i+1; j < length; j++) {
                    if (c[j] == c[j-1]) count++;
                    else break;
                }
                i += count-1;
                a += to_string(count) + b;
            }
        }
        return a;
    }
};