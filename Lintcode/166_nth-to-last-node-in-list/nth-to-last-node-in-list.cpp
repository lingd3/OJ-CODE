/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/nth-to-last-node-in-list
@Language: C++
@Datetime: 17-04-10 12:04
*/

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: Nth to last node of a singly linked list. 
     */
    ListNode *nthToLast(ListNode *head, int n) {
        // write your code here
        ListNode* first = head;
        ListNode* second = head;
        while (n--) {
            if (second != NULL) second = second->next;
        }
        while (second != NULL) {
            first = first->next;
            second = second->next;
        }
        return first;
    }
};


