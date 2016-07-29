class Solution {
public:
	//用log函数来判断，由于可能存在精度问题，所以判断时用绝对值小于...而不是直接用等号
    bool isPowerOfThree(int n) {
        if (n == 0) return false;
        double result = log(n)/log(3);
        if (abs(result-round(result)) <= 0.0000000001) return true;
        return false;
    }
};