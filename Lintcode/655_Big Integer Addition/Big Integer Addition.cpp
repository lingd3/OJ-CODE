class Solution {
public:
    /**
     * @param num1 a non-negative integers
     * @param num2 a non-negative integers
     * @return return sum of num1 and num2
     */
    string addStrings(string& num1, string& num2) {
        // Write your code here
        int s1 = num1.size();
        int s2 = num2.size();
        char sum[5500] = {'\0'};
        int d = 0;
        if (s1 <= s2) {
            int c = 0;
            for (int i = 0; i < s1; i++) {
                if (num1[s1-1-i]-'0'+num2[s2-1-i]-'0'+c >= 10) {
                    sum[d] = num1[s1-1-i]-'0'+num2[s2-1-i]+c-10;
                    c = 1;
                    d++;
                }
                else {
                    sum[d] = num1[s1-1-i]-'0'+num2[s2-1-i]+c;
                    c = 0;
                    d++;
                }
            }
            for (int i = s1; i < s2; i++) {
                if (num2[s2-1-i]-'0'+c >= 10) {
                    sum[d] = num2[s2-1-i]+c-10;
                    c = 1;
                    d++;
                }
                else {
                    sum[d] = num2[s2-1-i]+c;
                    c = 0;
                    d++;
                }
            }
            if (c == 1) {
                sum[d] = '1';
                d++;
            }
        }
        else {
            int c = 0;
            for (int i = 0; i < s2; i++) {
                if (num1[s1-1-i]-'0'+num2[s2-1-i]-'0'+c >= 10) {
                    sum[d] = num1[s1-1-i]-'0'+num2[s2-1-i]+c-10;
                    c = 1;
                    d++;
                }
                else {
                    sum[d] = num1[s1-1-i]-'0'+num2[s2-1-i]+c;
                    c = 0;
                    d++;
                }
            }
            for (int i = s2; i < s1; i++) {
                if (num1[s1-1-i]-'0'+c >= 10) {
                    sum[d] = num1[s1-1-i]+c-10;
                    c = 1;
                    d++;
                }
                else {
                    sum[d] = num1[s1-1-i]+c;
                    c = 0;
                    d++;
                }
            }
            if (c == 1) {
                sum[d] = '1';
                d++;
            }
        }
        char sum2[5500] = {'\0'};
        int k = 0;
        for (int i = d-1; i >= 0; i--) {
            sum2[k] = sum[i];
            k++;
        }
        string s = sum2;
        return s;
    }
};