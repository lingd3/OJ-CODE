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
    //一开始没看好题，一上来就借用哈希实现，后来发现题目写了“Given a sorted linked list”，苦逼了。。。
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        int a[10000] = {0};
        a[head->val+500] = 1;
        ListNode* temp = head;
        while (temp->next != NULL) {
            if (a[temp->next->val+500] == 1) {
                ListNode* temp1 = temp->next;
                temp->next = temp1->next;
                delete temp1;
            }
            else {
                a[temp->next->val+500]++;
                temp = temp->next;
            }
        }
        return head;
    }
};
//法二：
ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode* temp = head;
    while (temp->next != NULL) {
        if (temp->val == temp->next->val) {
            ListNode* temp1 = temp->next;
            temp->next = temp1->next;
            delete temp1;
        }
        else temp = temp->next;
    }
    return head;
}