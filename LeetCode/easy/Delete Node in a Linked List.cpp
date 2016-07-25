/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution { //这道题没delete掉node也可以AC，不过一定要delete 
public:
    void deleteNode(ListNode* node) {
        if (node == NULL) return;
        ListNode* temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
        delete temp;
    }
};
