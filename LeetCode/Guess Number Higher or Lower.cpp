// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int large = n;
        int small = 0;
        int mid;
        while (true) {
            if (large <= small) return small;
            mid = large/2+small/2;
            if (guess(mid) == -1) {
                large = mid-1;
            }
            else if (guess(mid) == 1) {
                small = mid+1;
            }
            else {
                return mid;
            }
        }
    }
};