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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(0, head), *tmp = dummy,
                 *part1_end = dummy, *rev_begin = nullptr, *rev_end = nullptr,
                 *part2_begin = nullptr;
        int i = 0;
        while (i < left - 1)
            tmp = tmp->next, i++;
        part1_end = tmp;
        tmp = tmp->next, rev_begin = tmp;
        part1_end->next == nullptr;
        i++;
        while (i < right)
            tmp = tmp->next, i++;

        rev_end = tmp;
        part2_begin = tmp->next;
        rev_end->next = nullptr;
        reverse(rev_begin, nullptr);
        part1_end->next = rev_end;
        rev_begin->next = part2_begin;
        return dummy->next;
    }

    void reverse(ListNode* head, ListNode* tail) {
        if (!head)
            return;
        ListNode* next_head = head->next;
        head->next = tail;
        ListNode* next_tail = head;
        reverse(next_head, next_tail);
    }
};