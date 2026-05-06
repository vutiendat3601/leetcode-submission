/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0, head), *prev = dummy;
        int i = 0;
        while (head) {
            if (!(i & 1) && head->next) {
                ListNode *nxt = head->next, *nxt2 = nxt->next;
                prev->next = nxt, nxt->next = head, head->next = nxt2;
            } else {
                head = head->next;
            }
            prev = prev->next;
            i++;
        }
        return dummy->next;
    }
};