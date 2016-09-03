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
    //申请空间来实现
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;
        vector<int> v;
        ListNode* temp = head;
        while (temp != NULL) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        for (int i = 0, j = v.size()-1; i < j; i++, j--) {
            if (v[i] != v[j]) return false;
        }
        return true;
    }
};
//翻转链表，O(1) space
bool isPalindrome(ListNode* head) {
    if (head == NULL || head->next == NULL) return true;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverseList(slow->next);
    slow = slow->next;
    while (slow != NULL) {
        if (head->val != slow->val) return false;
        head = head->next;
        slow = slow->next;
    }
    return true;
}
ListNode* reverseList(ListNode* head) {
    ListNode* pre = NULL;
    ListNode* next = NULL;
    while (head != NULL) {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}













