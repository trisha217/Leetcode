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
    ListNode* head=NULL;
    int len = 0;
    Solution(ListNode* h) {
        head = h;
        while(h){
            h = h->next;
            len++;
        }
    }
    
    int getRandom() {
        int x = random()%len;
        ListNode* h=head;
        while(h){
            if(x-- == 0)
                return h->val;
            h = h->next;
        }
        return head->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */