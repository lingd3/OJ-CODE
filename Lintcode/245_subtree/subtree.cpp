/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/subtree
@Language: C++
@Datetime: 17-02-26 11:55
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        // write your code here
        if (T2 == NULL || T1 == NULL && T2 == NULL) return true;
        if (T1 == NULL) return false;
        bool result = false;
        if (T1->val == T2->val) 
            result = hasSubtree(T1, T2);
        if (!result) 
            result = isSubtree(T1->left, T2);
        if (!result) 
            result = isSubtree(T1->right, T2);
        return result;
    }
    
    bool hasSubtree(TreeNode *T1, TreeNode *T2) {
        if (T1 == NULL && T2 == NULL) return true;
        if (T1 == NULL || T2 == NULL) return false;
        if (T1->val != T2->val) return false;
        return hasSubtree(T1->left, T2->left) && hasSubtree(T1->right, T2->right);
    }
    
    
    
};




