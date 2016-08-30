class Solution {
public:
    string convertToTitle(int n) {
        string a;
        int i;
        while (n) {
            i = n % 26;
            if (i == 0) {
                a.insert(0, 1, 'Z');
                n = n/26-1;
            }
            else {
                a.insert(0, 1, i+64);
                n = n / 26;
            }
        }
        return a;
    }
};
/*
递归方法
string convertToTitle(int n) {
    if (n == 0) return "";
    int s = (n-1)/ 26;
    int t = (n-1) % 26;
    return convertToTitle(s) + (char)(t+65);
}
*/