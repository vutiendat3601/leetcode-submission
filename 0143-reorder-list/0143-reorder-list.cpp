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
    void reorderList(ListNode* head) {
        ListNode *fs = head->next, *sl = head, *tail = nullptr;
        while (fs && fs->next)
            sl = sl->next, fs = fs->next->next;

        ListNode* tmp = sl->next;
        sl->next = nullptr;
        sl = tmp;
        while (sl) {
            ListNode* nextSl = sl->next;
            sl->next = tail;
            tail = sl;
            sl = nextSl;
        }
        ListNode *node = new ListNode(), *h1 = head, *h2 = tail;

        while (h1 && h2) {
            ListNode *nextH1 = h1->next, *nextH2 = h2->next;
            h1->next = nullptr, h2->next = nullptr;
            node->next = h1, node = node->next;
            node->next = h2, node = node->next;
            h1 = nextH1;
            h2 = nextH2;
        }
        if (h1)
            node->next = h1;

        if (h2)
            node->next = h2;
    }
};