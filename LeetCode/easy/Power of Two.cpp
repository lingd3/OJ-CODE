class Solution {
public:
    bool isPowerOfTwo(int n) {
        for (int i = 0; ;i++) {
            if (pow(2, i) == n) return true;
            else if (pow(2, i) > n) break;
        }
        return false;
    }

    //法二
    bool isPowerOfTwo(int n) {
        return n<=0? false: !(n&(n-1));
    }
};