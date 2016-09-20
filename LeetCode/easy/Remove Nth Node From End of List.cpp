/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public: //用两个指针，一个先走n步然后在同时走，当后面的指针走到最后时前面的指针所在的位置就是所求的位置
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return head;
        ListNode* temp = head;
        ListNode* temp1 = head;
        while (n-- && temp1 != NULL) {
            temp1 = temp1->next;
        }
        if (temp1 == NULL) {
            head = head->next;
            delete temp;
            return head;
        }
        while (temp1->next != NULL) {
            temp = temp->next;
            temp1 = temp1->next;
        }
        temp1 = temp->next;
        temp->next = temp1->next;
        delete temp1;
        return head;
    }
};