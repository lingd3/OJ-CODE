class Solution {
public:
    string addStrings(string num1, string num2) {
        char sum[10500] = {'\0'};
        int carry = 0, d1 = num1.size(), d2 = num2.size(), j = 0, i;
        for (i = 1; ; i++) {
            if (i > d1 || i > d2) break;
            if (num1[d1-i] + num2[d2-i] + carry -'0' - '0' >= 10) {
                sum[j] = num1[d1-i] + num2[d2-i] + carry -'0'-10;
                j++;
                carry = 1;
            }
            else {
                sum[j] = num1[d1-i] + num2[d2-i] + carry -'0';
                j++;
                carry = 0;
            }
        }
        if (d1 == d2 && carry == 1) {
            sum[j] = '1';
            carry = 0;
            j++;
        }
        else if (d1 > d2) {
            for (int k = d1-i; k >= 0; k--) {
                if (num1[k] - '0' + carry >= 10) {
                    sum[j] = num1[k] + carry -10;
                    carry = 1;
                    j++;
                }
                else {
                    sum[j] = num1[k]+carry;
                    carry = 0;
                    j++;
                }
            }
        }
        else {
            for (int k = d2-i; k >= 0; k--) {
                if (num2[k] - '0' + carry >= 10) {
                    sum[j] = num2[k] + carry -10;
                    carry = 1;
                    j++;
                }
                else {
                    sum[j] = num2[k]+carry;
                    carry = 0;
                    j++;
                }
            }
        }
        if (carry == 1) {
            sum[j] = '1';
            j++;
        }
        char sum1[10500] = {'\0'};
        int k = 0;
        for (int i = j-1; i >= 0; i--) {
            sum1[k] = sum[i];
            k++;
        }
        
        string a(sum1);
        return a;
    }
};