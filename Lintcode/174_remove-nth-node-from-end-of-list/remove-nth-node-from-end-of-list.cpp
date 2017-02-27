/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/remove-nth-node-from-end-of-list
@Language: C++
@Datetime: 17-02-25 14:15
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
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        if (head == NULL) return NULL;
        ListNode *p1 = head;
        ListNode *p2 = head;
        for (int i = 0; i < n; i++) {
            if (p1->next != NULL) p1 = p1->next;
            else {
                ListNode *temp1 = head;
                head = head->next;
                delete temp1;
                return head;
            }
        }
        while (p1->next != NULL) {
            p1 = p1->next;
            p2 = p2->next;
        }
        ListNode *temp = p2->next;
        p2->next = temp->next;
        delete temp;
        return head;
    }
};


