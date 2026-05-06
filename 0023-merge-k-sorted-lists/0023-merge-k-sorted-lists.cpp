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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* preRoot = new ListNode();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& node : lists)
            while (node)
                pq.push(node->val), node = node->next;

        ListNode* head = preRoot;
        while (pq.size())
            head->next = new ListNode(pq.top()), pq.pop(), head = head->next;

        return preRoot->next;
    }
};

// Priority Queue