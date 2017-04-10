/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/longest-words
@Language: C++
@Datetime: 17-04-10 12:23
*/

class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        vector<string> v;
        if (dictionary.size() == 0) return v;
        int maxLen = dictionary[0].size(), size = dictionary.size();
        queue<string> q;
        for (int i = 0; i < size; i++) {
            if (dictionary[i].size() == maxLen) {
                q.push(dictionary[i]);
            }
            else if (dictionary[i].size() < maxLen) continue;
            else {
                maxLen = dictionary[i].size();
                while (!q.empty()) q.pop();
                q.push(dictionary[i]);
            }
        }
        while (!q.empty()) {
            v.push_back(q.front());
            q.pop();
        }
        return v;
    }
};