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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {INT_MAX, -1};
        int lastIdx = -1, i = 1, firstIdx = -1;
        ListNode* pre = head;
        head = head->next;
        while (head && head->next) {
            bool valid =
                (pre->val < head->val && head->val > head->next->val) ||
                (pre->val > head->val && head->val < head->next->val);
            if (valid) {
                if (firstIdx > -1)
                    ans[1] = i - firstIdx;
                else
                    firstIdx = i;

                if (lastIdx > -1)
                    ans[0] = min(ans[0], i - lastIdx);

                lastIdx = i;
            }
            i++, pre = head, head = head->next;
        }
        ans[0] = ans[1] == -1 ? -1 : ans[0];
        return ans;
    }
};