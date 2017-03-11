/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/convert-binary-search-tree-to-doubly-linked-list
@Language: C++
@Datetime: 17-03-11 06:54
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
 * Definition of Doubly-ListNode
 * class DoublyListNode {
 * public:
 *     int val;
 *     DoublyListNode *next, *prev;
 *     DoublyListNode(int val) {
 *         this->val = val;
           this->prev = this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of tree
     * @return: the head of doubly list node
     */
     
    DoublyListNode* list = NULL;
    DoublyListNode* bstToDoublyList(TreeNode* root) {
        // Write your code here
        if (root == NULL) return NULL;
        inorder(root);
        while (list->prev != NULL) list = list->prev;
        return list;
    }
    
    void inorder(TreeNode* root) {
        if (root->left != NULL) inorder(root->left);
        DoublyListNode* temp = new DoublyListNode(root->val);
        if (list == NULL) {
            list = temp;
        }
        else if (list != NULL) {
            list->next = temp;
            temp->prev = list;
            list = temp;
        }
        if (root->right != NULL) inorder(root->right);
    }
};

