class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x^y, q = 0;
        while (z != 0) {
            if (z%2 != 0) q++;
            z = z >> 1;
        }
        return q;
    }
};