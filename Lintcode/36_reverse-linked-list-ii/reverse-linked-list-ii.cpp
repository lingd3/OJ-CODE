/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/reverse-linked-list-ii
@Language: C++
@Datetime: 17-02-26 09:54
*/

/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write your code here
        if (head == NULL || head->next == NULL || m == n) return head;
        if (m == 1) {
            ListNode* temp = head;
            for (int i = 1; i < n; i++) {
                temp = temp->next;
            }
            ListNode* temp1 = temp->next;
            temp->next = NULL;
            head = reverse(head);
            temp = head;
            while (temp->next != NULL) temp = temp->next;
            temp->next = temp1;
            return head;
        }
        ListNode* first = head;
        for (int i = 2; i < m; i++) {
            first = first->next;
        }
        ListNode* temp = first->next;
        first->next = NULL;
        ListNode* temp1 = temp;
        for (int i = m; i < n; i++) {
            if (temp != NULL) temp = temp->next;
        }
        ListNode* third;
        if (temp != NULL) third = temp->next;
        else third = NULL;
        if (temp != NULL) temp->next = NULL;
        // return temp1;
        ListNode *second = reverse(temp1);
        first->next = second;
        temp = second;
        while (temp->next != NULL) temp = temp->next;
        temp->next = third;
        return head;
    }
    
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
