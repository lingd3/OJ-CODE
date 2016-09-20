/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public: //用两个指针，让长度长的先走到跟短的一样，然后两个同时走，走到相同的node就是所求的node
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp = headA;
        int countA = 0;
        while (temp != NULL) {
            countA++;
            temp = temp->next;
        }
        ListNode* temp1 = headB;
        int countB = 0;
        while (temp1 != NULL) {
            countB++;
            temp1 = temp1->next;
        }
        temp = headA;
        temp1 = headB;
        if (countA > countB) {
            int i = countA-countB;
            while (i-- && temp != NULL) {
                temp = temp->next;
            }
        }
        else if (countA < countB) {
            int i = countB-countA;
            while (i-- && temp1 != NULL) {
                temp1 = temp1->next;
            }
        }
        while (temp != NULL && temp->val != temp1->val) {
            temp = temp->next;
            temp1 = temp1->next;
        }
        return temp;
    }
};