/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/intersection-of-two-linked-lists
@Language: C++
@Datetime: 17-03-11 09:32
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
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // write your code here
        if (headA == NULL || headB == NULL) return NULL;
        int aLen = 1, bLen = 1;
        ListNode *temp1 = headA;
        while (temp1->next != NULL) {
            aLen++;
            temp1 = temp1->next;
        }
        ListNode *temp2 = headB;
        while (temp2->next != NULL) {
            bLen++;
            temp2 = temp2->next;
        }
        if (temp1 != temp2) return NULL;
        temp1 = headA;
        temp2 = headB;
        if (aLen >= bLen) {
            for (int i = 0; i < aLen-bLen; i++) {
                temp1 = temp1->next;
            }
        }
        else if (aLen < bLen) {
            for (int i = 0; i < bLen-aLen; i++) {
                temp2 = temp2->next;
            }
        }
        while (temp1 != NULL) {
            if (temp1 == temp2) return temp1;
            else {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        return NULL;
    }
};








