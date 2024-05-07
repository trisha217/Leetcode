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
  ListNode* doubleIt(ListNode* y) {
    //  x   y   z 
    // pre cur nex
    ListNode* x = NULL;
    while (y) {
      ListNode* z = y->next;
      y->next = x;
      x = y;
      y = z;
    }
    y = x;
    x = NULL;
    int c = 0;
    while (y) {
      // update and reverse
      int val = c + (y->val * 2);
      y->val = val % 10;
      c = val / 10;
      ListNode* z = y->next;
      y->next = x;
      x = y;
      y = z;
    }
    return c ? new ListNode(c, x) : x;
  }
};