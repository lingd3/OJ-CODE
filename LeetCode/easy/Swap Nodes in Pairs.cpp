/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public: //递归也可以
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* temp = head;
        head = temp->next;
        temp->next = head->next;
        head->next = temp;
        while (temp->next != NULL && temp->next->next != NULL) {
            ListNode* temp1 = temp->next;
            temp->next = temp1->next;
            temp1->next = temp->next->next;
            temp->next->next = temp1;
            temp = temp->next->next;
        }
        return head;
    }
};