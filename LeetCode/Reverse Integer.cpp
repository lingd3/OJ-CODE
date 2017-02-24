class Solution {
public:
    int reverse(int x) {
        if (x == 2147483647 || x == -2147483648) return 0;
        int t = 1;
        if (x < 0) {
            t = -1;
            x = x*(-1);
        }
        int a[20] = {0}, count = 0;
        if (x == 0) count = 1;
        while (x) {
            a[count] = x%10;
            x /= 10;
            count++;
        }
        int i;
        for (i = 0; i < count; i++) {
            if (a[i] != 0) break;
        }
        if (count-i > 10) return 0;
        int sum = 0;
        for (int j = i; j < count; j++) {
            if (2147483647 - pow(10, count-j-1)*a[j] < sum) return 0; //相加可能会溢出，所以用相减
            sum += pow(10, count-j-1)*a[j];
        }
        if (t*sum > 2147483647 || t*sum < -2147483648) return 0;
        return t*sum;
    }
};
//另一个聪明的做法
int reverse(int x) {
    int ans = 0;
    while (x) {
        int temp = ans * 10 + x % 10;
        if (temp / 10 != ans) 
            return 0;
        ans = temp;
        x /= 10;
    }
    return ans;
}

