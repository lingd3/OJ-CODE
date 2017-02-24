//如果石头是4的倍数，那么肯定输
//否则，先拿的先拿走若干，保证剩下的石头的4的倍数，肯定赢
class Solution {
public:
    bool canWinNim(int n) {
        if (n % 4 == 0) return false;
        return true;
    }
};