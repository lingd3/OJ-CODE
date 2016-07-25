class Solution {
public:
    bool isHappy(int n) {
    if (n == 1) return true;
	int sum, k=0;
	while (1) {
		sum = 0;
		while (n) {
			sum += (n%10)*(n%10);
			n /= 10;
		}
		if (sum == 1) return true;
		else {
			k++;
			n = sum;
			if (k > 1000) return false;
		}
	}
    }
};
