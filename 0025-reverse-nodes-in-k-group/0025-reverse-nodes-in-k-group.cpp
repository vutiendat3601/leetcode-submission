/**
 * Definition for singly-linked list->
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* reverseList(ListNode* head, ListNode* tail) {
        if (!head)
            return tail;
        ListNode* nxt = head->next;
        head->next = tail;
        return reverseList(nxt, head);
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(-1), *tail = dummy, *node = head;
        dummy->next = head;
        int i = 0;
        while (node) {
            i++;
            if (i % k == 0) {
                ListNode* nxt = node->next;
                node->next = nullptr;
                ListNode *reversed = reverseList(tail->next, nullptr),
                         *nxtTail = tail->next;
                tail->next = reversed, tail = nxtTail, tail->next = nxt;
                node = nxt, dummy->next = i == k ? reversed : dummy->next;
            } else {
                node = node->next;
            }
        }
        return dummy->next;
    }
};