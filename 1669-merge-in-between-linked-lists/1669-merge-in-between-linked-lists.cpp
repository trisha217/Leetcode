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
        ListNode* x = list1;
        ListNode* y = list2;
        ListNode* z = x;
        while(y->next != NULL)y = y->next;
        for(int i = 1 ;i < b;i++){
            if(i < a ){
                x = x->next;
                z = x;
            }else z = z->next;
        }
        y->next = (z->next->next);
        x->next = list2;
        return list1;
    }
};