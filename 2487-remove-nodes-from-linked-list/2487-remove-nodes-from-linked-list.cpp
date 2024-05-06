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
    ListNode* reverse(ListNode* node){
        ListNode* prev = NULL;
        ListNode* cur = node;
        while(cur){
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        ListNode* node = reverse(head);
        ListNode* track = node;
        while(node){
            int maxi = node->val;
            while(node->next && maxi>node->next->val){
                node->next = node->next->next ? node->next->next : NULL;
            }
            node = node->next;
        }
        return reverse(track);
    }
};