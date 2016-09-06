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
    //递归做法
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* temp = reverseList(head->next);
        head->next = NULL;
        ListNode* temp1 = temp;
        while (temp1->next != NULL) {
            temp1 = temp1->next;
        }
        temp1->next = head;
        return temp;
    }
};
//非递归
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* temp = head->next;
        ListNode* temp1 = temp->next;
        head->next = NULL;
        temp->next = head;
        head = temp;
        while (temp1 != NULL) {
            temp = temp1;
            temp1 = temp1->next;
            temp->next = head;
            head = temp;
        }
        return temp;
    }
};