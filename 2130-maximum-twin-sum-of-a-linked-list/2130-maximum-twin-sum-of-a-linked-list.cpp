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
    int pairSum(ListNode* head) {
        ListNode* mid = NULL;
        ListNode* fast = head, *slow = head;
        while(fast != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;
        slow->next = NULL;

        ListNode* prev = NULL, *curr = temp, *tmp = temp;

        while(curr != NULL){
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        int ans = 0;
        while(head != NULL && prev != NULL){
            int data = head->val + prev->val;
            head = head->next;
            prev = prev->next;
            ans = max(data,ans);
        }
        return ans;
    }
};