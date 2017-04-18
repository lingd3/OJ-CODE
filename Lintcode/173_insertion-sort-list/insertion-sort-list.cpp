/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/insertion-sort-list
@Language: C++
@Datetime: 17-04-18 10:05
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
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        // write your code here
        if (head == NULL || head->next == NULL) return head;
        ListNode* last_sorted = head;
        ListNode* temp = head->next;
        while (temp != NULL) {
            if (temp->val >= last_sorted->val) {
                temp = temp->next;
                last_sorted = last_sorted->next;
            }
            else {
                ListNode* temp2 = temp;
                last_sorted->next = temp->next;
                temp = last_sorted->next;
                //将temp2插入到正确位置
                if (head->val > temp2->val) {
                    temp2->next = head;
                    head = temp2;
                }
                else {
                    ListNode* temp3 = head;
                    while (temp3->next->val < temp2->val) {
                        temp3 = temp3->next;
                    }
                    temp2->next = temp3->next;
                    temp3->next = temp2;
                }
            }
        }
        return head;
    }
};
