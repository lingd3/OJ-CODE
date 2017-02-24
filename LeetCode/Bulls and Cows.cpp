class Solution {
public:
    string getHint(string secret, string guess) {
        int a[10] = {0};
        int countA = 0, countB = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) countA++;
            a[secret[i]-'0']++;
        }
        for (int i = 0; i < secret.size(); i++) {
            if (a[guess[i]-'0'] > 0) {
                countB++;
                a[guess[i]-'0']--;
            }
        }
        countB -= countA;
        string a1, b;
        char c[256], d[256];
        sprintf(c, "%d", countA);
        sprintf(d, "%d", countB);
        a1 = c;
        b = d;
        return a1+"A"+b+"B";
    }
};