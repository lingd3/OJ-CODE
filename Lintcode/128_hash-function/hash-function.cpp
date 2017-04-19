/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/hash-function
@Language: C++
@Datetime: 17-04-19 13:39
*/

class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        // write your code here
        int size = key.size();
        long long sum = 0;
        for (int i = 0; i < size; i++) {
            sum = sum*33 % HASH_SIZE + (int)key[i];
        }
        return sum%HASH_SIZE;
    }
};
