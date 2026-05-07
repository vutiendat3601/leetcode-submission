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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return head;
        unordered_map<int, ListNode*> nodes;
        ListNode* orig = head;
        int i = 0, n = 0;
        while (head)
            nodes[i++] = head, head = head->next;
        n = nodes.size(), k %= n;
        if (!k)
            return orig;
        nodes[n - 1 - k]->next = nullptr;
        nodes[n - 1]->next = orig;
        return nodes[n - k];
    }
};