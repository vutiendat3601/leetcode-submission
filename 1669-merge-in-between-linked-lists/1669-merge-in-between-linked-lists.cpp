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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // Find a
        ListNode *prevA = nullptr, *nodeB = list1;
        int i = 0;
        while (i < a) {
            prevA = nodeB;
            nodeB = nodeB->next;
            i++;
        }
        // Find b
        // nodeB = prevA->next;
        while (i < b) {
            nodeB = nodeB->next;
            i++;
        }
        ListNode* nextB = nodeB->next;
        prevA->next = list2;
        nodeB->next = nullptr;
        while (list2) {
            if (!list2->next) {
                list2->next = nextB;
                break;
            }
            list2 = list2->next;
        }
        return list1;
    }
};