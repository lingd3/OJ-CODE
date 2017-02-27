/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/reverse-linked-list
@Language: C++
@Datetime: 17-02-25 04:03
*/

/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
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
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* temp = head;
        head = head->next;
        temp->next = NULL;
        while (head != NULL) {
            ListNode* temp1 = head;
            head = head->next;
            temp1->next = temp;
            temp = temp1;
        }
        return temp;
    }
};
