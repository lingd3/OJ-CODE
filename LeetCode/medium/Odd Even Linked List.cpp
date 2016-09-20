/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public: //将链表分为两部分
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) return head;
        ListNode* temp = head;
        ListNode* head2 = head->next;
        ListNode* temp1 = head2;
        while (temp != NULL && temp1 != NULL && temp->next != NULL && temp1->next != NULL) {
            temp->next = temp1->next;
            temp1->next = temp1->next->next;
            temp = temp->next;
            temp1 = temp->next;
        }
        temp->next = head2;
        return head;
    }
};