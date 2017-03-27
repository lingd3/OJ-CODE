/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/linked-list-cycle-ii
@Language: C++
@Datetime: 17-03-21 09:31
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
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        // write your code here
        if (head == NULL || head->next == NULL) return NULL;
        ListNode *fast = head;
        ListNode *slow = head;
        bool hasRing = false;
        while (slow != NULL && fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                hasRing = true;
                break;
            }
        }
        if (!hasRing) return NULL;
        fast = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};



