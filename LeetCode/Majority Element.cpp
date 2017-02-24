class Solution {
public:
    int majorityElement(vector<int>& nums) {//先排序，中间值必是出现次数大于n/2的值
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};
//用哈希表也可实现

//还有一种叫做Moore voting algorithm的方法，每找出两个不同的element，就成对删除即count--，最终剩下的一定就是所求的。
//时间复杂度：O(n)
int majorityElement(vector<int>& nums) {
	int elem = 0;
	int count = 0;
	for(int i = 0; i < nums.size(); i++)  {
		if(count == 0)  {
			elem = nums[i];
			count = 1;
		}
		else {
			if(elem == nums[i])
				count++;
			else
				count--;
		}
	}
	return elem;
}