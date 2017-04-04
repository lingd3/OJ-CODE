/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/add-two-numbers
@Language: C++
@Datetime: 17-04-04 08:53
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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // write your code here
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode *head = NULL;
        ListNode *temp = head;
        int carry = 0;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val + l2->val + carry >= 10) {
                if (head == NULL) {
                    head = new ListNode(l1->val+l2->val+carry-10);
                    temp = head;
                    carry = 1;
                }
                else {
                    ListNode *temp2 = new ListNode(l1->val+l2->val+carry-10);
                    temp->next = temp2;
                    temp = temp->next;
                    carry = 1;
                }
            }
            else {
                if (head == NULL) {
                    head = new ListNode(l1->val+l2->val+carry);
                    temp = head;
                    carry = 0;
                }
                else {
                    ListNode *temp2 = new ListNode(l1->val+l2->val+carry);
                    temp->next = temp2;
                    temp = temp->next;
                    carry = 0;
                }
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 == NULL) {
            while (l2 != NULL) {
                if (l2->val+carry >= 10) {
                    temp->next = new ListNode(l2->val+carry-10);
                    temp = temp->next;
                    carry = 1;
                }
                else {
                    temp->next = new ListNode(l2->val+carry);
                    temp = temp->next;
                    carry = 0;
                }
                l2 = l2->next;                
            }
        }
        else if (l2 == NULL) {
            while (l1 != NULL) {
                if (l1->val+carry >= 10) {
                    temp->next = new ListNode(l1->val+carry-10);
                    temp = temp->next;
                    carry = 1;
                }
                else {
                    temp->next = new ListNode(l1->val+carry);
                    temp = temp->next;
                    carry = 0;
                }
                l1 = l1->next;                
            }
        }
        if (carry == 1) {
            temp->next = new ListNode(1);
        }
        return head;
    }
};








