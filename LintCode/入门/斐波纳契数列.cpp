class Solution {
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        // write your code here
        int a[100], i;
        a[0] = 0;
        a[1] = 0;
        a[2] = 1;
        for (i = 3; i <= n; i++) {
            a[i] = a[i-1] + a[i-2];
        }
        return a[n];
    }
};

