//利用哈希表
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a[100000] = {0};
        for (int i = 0; i < nums.size(); i++) {
            a[nums[i]+50000]++;
        }
        for (int i = 0; i < 100000; i++) {
            if (a[i] == 1) return i-50000;
        }
        return 0;
    }
};
//用异或的方法
//因为A XOR A = 0,且XOR运算是可交换的,于是,对于实例{2,1,4,5,2,4,1}就会有这样的结果：
//(2^1^4^5^2^4^1) => ((2^2)^(1^1)^(4^4)^(5)) => (0^0^0^5) => 5
int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int i = 0; i < nums.size(); i++) {
        result ^= nums[i];
    }
    return result;
}
















