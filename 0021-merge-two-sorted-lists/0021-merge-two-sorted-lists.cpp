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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(), *head = dummy;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                ListNode* next_list1 = list1->next;
                list1->next == nullptr, head->next = list1, list1 = next_list1;
            } else {
                ListNode* next_list2 = list2->next;
                list2->next == nullptr, head->next = list2, list2 = next_list2;
            }
            head = head->next;
        }
        if (list1)
            head->next = list1;

        if (list2)
            head->next = list2;

        return dummy->next;
    }
};

// 2-pointers, time: O(n), space: O(1)