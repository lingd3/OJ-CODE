/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/linked-list-cycle
@Language: C++
@Datetime: 17-03-14 06:13
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
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        // write your code here
        if (head == NULL || head->next == NULL) return false;
        ListNode *temp = head;
        ListNode *temp1 = head;
        while (temp != NULL && temp1 != NULL && temp1->next != NULL) {
            temp1 = temp1->next;
            if (temp->val == temp1->val) return true;
            else {
                temp = temp->next;
                temp1 = temp1->next;
            }
        }
        return false;
    }
};


