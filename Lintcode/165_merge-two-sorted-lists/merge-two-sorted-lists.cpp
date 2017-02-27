/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/merge-two-sorted-lists
@Language: C++
@Datetime: 17-02-25 13:59
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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode* l = NULL;
        if (l1->val <= l2->val) {
            l = l1;
            l1 = l1->next;
            l->next = NULL;
        }
        else if (l1->val > l2->val) {
            l = l2;
            l2 = l2->next;
            l->next = NULL;
        }
        ListNode* l3 = l;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                l->next = l1;
                l = l->next;
                l1 = l1->next;
            }
            else if (l1->val > l2->val) {
                l->next = l2;
                l = l->next;
                l2 = l2->next;
            }
        }
        if (l1 == NULL) {
            while (l2 != NULL) {
                l->next = l2;
                l = l->next;
                l2 = l2->next;
            }
        }
        else if (l2 == NULL) {
            while (l1 != NULL) {
                l->next = l1;
                l = l->next;
                l1 = l1->next;
            }
        }
        return l3;
    }
};