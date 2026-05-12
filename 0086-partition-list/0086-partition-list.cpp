/**
 * Definition for singly-linked list->
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptrptr) {}
 *     ListNode(int x) : val(x), next(nullptrptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy = new ListNode(-101, head), *prevNode = dummy;

        while (head) {
            if (head->val >= x)
                break;
            prevNode = head, head = head->next;
        }
        if (head) {
            ListNode* tmp = nullptr;
            while (head->next) {
                tmp = head, head = head->next;
                if (head->val < x) {
                    tmp->next = head->next;
                    head->next = prevNode->next;
                    prevNode->next = head;
                    prevNode = prevNode->next;
                    head = tmp;
                }
            }
        }
        return dummy->next;
    }
};