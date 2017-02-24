class Solution {
public:
    int countPrimes(int n) {
        bool *a = new bool[n];
        int i, j;
        for (i = 2; i < n; i++) a[i] = true;
        for (i = 2; i*i < n; i++) {
            if (!a[i]) continue;
            for (j = i+i; j < n; j = j+i) {
                a[j] = false;
            }
        }
        int count = 0;
        for (i = 2; i < n; i++) {
            if (a[i] == true) count++;
        }
        return count;
    }
};
