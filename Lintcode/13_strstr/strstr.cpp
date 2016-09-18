/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/strstr
@Language: C++
@Datetime: 16-09-11 04:54
*/

class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        if (source == NULL || target == NULL) return -1; 
        string a(source);
        string b(target);
        if (a.size() > 10000) return -1;
        if (b == "") return 0;
        if (a == b) return 0;
        int i, j, l;
    	for (i = 0; i < a.size(); i++) {
    		if (a[i] == b[0]) {
    			l = i;
    			for (j = 0; j < b.size(); j++) {
    				if (b[j] == a[l]) {
    					l++;
    					continue;
    				}
    				else break;
    			}
    			if (j == b.size()) return i;
    			else continue;
    		}
    	}
    	return -1;
    }
};
