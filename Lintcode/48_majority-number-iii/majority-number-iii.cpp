/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/majority-number-iii
@Language: C++
@Datetime: 17-03-17 13:41
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        int a[10000], b[10000], j, l = 1;
        for (int i = 0; i < 100; i++) {
            a[i] = 0;
            b[i] = 0;
        }
        a[0] = nums[0];
        b[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (j = 0; j < k-1; j++) {
                if (nums[i] == a[j]) break;
            }
            if (j == k-1) {
                a[l] = nums[i];
                b[l] = 0;
                l++;
            }
        }
        
    //    for (int i = 0; i < k-1; i++) {
    //        cout << a[i] << " " << b[i] << endl;
    //    }
        
        for (int i = 1; i < nums.size(); i++) {
            for (j = 0; j < k-1; j++) {
                if (nums[i] == a[j]) {
                    b[j]++;
                    break;
                }
            }
            if (j == k-1) {
                int min = b[0], minindex = 0;
                for (int j = 1; j < k-1; j++) {
                    if (min > b[j]) {
                        min = b[j];
                        minindex = j;
                    }
                }
                if (b[minindex] == 1) {
                    a[minindex] = nums[i];
                    b[minindex] = 1;
                }
                else b[minindex]--;
            }
        }
        
        int count[10000] = {0};
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < k-1; j++) {
                if (nums[i] == a[j]) count[a[j]]++;
            }
        }
        int max = 0, maxindex = 0;
        for (int i = 0; i < 10000; i++) {
            if (max < count[i]) {
                max = count[i];
                maxindex = i;
            }
        }
        return maxindex;
    }
};





















