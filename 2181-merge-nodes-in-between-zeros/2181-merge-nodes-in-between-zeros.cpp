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
    ListNode* mergeNodes(ListNode* head) {
        ListNode * current = head->next;
        ListNode * temp =current;
        while(temp != nullptr){
            int sum=0;
            while(temp->val != 0){
                sum+= temp->val;
                temp = temp->next;
            }
            current->val = sum;
            temp = temp->next;
            current->next=temp;
            current=current->next;

        }
        return head->next;
    }
};