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
    ListNode* removeElements(ListNode* head, int val) {
        while (head != NULL && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        if (head == NULL) return head;
        ListNode* temp = head;
        while (temp->next != NULL) {
            if (temp->next->val == val) {
                ListNode* temp1 = temp->next;
                temp->next = temp1->next;
                delete temp1;
            }
            else {
                temp = temp->next;
            }
        }
        return head;
    }
};