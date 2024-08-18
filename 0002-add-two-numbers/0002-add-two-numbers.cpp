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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummynode = new ListNode(-1);
        ListNode* temp = dummynode;
         ListNode* cur = dummynode;
        int carry = 0;
        while(l1 != NULL || l2 != NULL) {
            int sum = carry;
            if(l1){
                sum+= l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2 = l2->next;
            }
            ListNode* newNode = new ListNode(sum%10);
            carry = sum/10;
            cur->next = newNode;
            cur = cur->next;
        }
        if(carry){
            ListNode* newNode = new ListNode(carry);
            cur->next = newNode;
            cur = cur->next;      
        }     
        return dummynode->next;
    }
};