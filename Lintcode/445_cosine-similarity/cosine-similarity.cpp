/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/cosine-similarity
@Language: C++
@Datetime: 17-04-04 09:15
*/

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        // write your code here
        double a0 = 0, a1 = 0, a2 = 0;
        for (int i = 0; i < A.size(); i++) {
            a1 += (A[i]*A[i]);
            a2 += (B[i]*B[i]);
        }
        a1 = sqrt(a1);
        a2 = sqrt(a2);
        if (a1 == 0 || a2 == 0) return 2.0000;
        for (int i = 0; i < A.size(); i++) {
            a0 += (A[i]*B[i]);
        }
        return a0/(a1*a2);
    }
};
