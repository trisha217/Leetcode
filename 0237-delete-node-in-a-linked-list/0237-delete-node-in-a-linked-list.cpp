/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        while (node != NULL && node->next != NULL) {
            node->val = node->next->val;
            if (node->next->next == NULL) {
                delete node->next;
                node->next = NULL;
            } else {
                node = node->next;
            }
        }
    }
};