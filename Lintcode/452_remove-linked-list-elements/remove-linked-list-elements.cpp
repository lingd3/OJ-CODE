/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/remove-linked-list-elements
@Language: C++
@Datetime: 16-08-02 07:58
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    /**
     * @param head a ListNode
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        if (head == NULL) return head;
        while (head != NULL && head->val == val) {
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }
        if (head == NULL) return NULL;
        ListNode *temp1 = head;
        for (; temp1 != NULL, temp1->next != NULL;) {
            if (temp1->next->val == val) {
                ListNode *temp2 = temp1->next;
                temp1->next = temp2->next;
                delete temp2;
            } else {
                temp1 = temp1->next;
            }
        }
        return head;
    }
};