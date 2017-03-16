/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/remove-duplicates-from-sorted-list
@Language: C++
@Datetime: 17-03-14 06:01
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
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        if (head == NULL || head->next == NULL) return head;
        ListNode *temp = head;
        while (temp->next != NULL) {
            ListNode *temp1 = temp->next;
            if (temp->val == temp1->val) {
                temp->next = temp1->next;
                delete temp1;
                temp1 = NULL;
            }
            else temp = temp->next;
        }
        return head;
    }
};