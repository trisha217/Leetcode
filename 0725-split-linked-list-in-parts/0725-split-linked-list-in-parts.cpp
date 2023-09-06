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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = 0;
        ListNode* p = head;
        while(p) {
            size++;
            p = p->next;
        }
        
        vector<ListNode*> ans(k, NULL);
        int num = size / k;
        int ext = size % k;
        ListNode* curr = head;
        for(int i = 0; i < k; i++) {
            int n = num;
            n += (ext > 0) ? 1 : 0;
            ext--;
            ListNode* root = curr;
            ListNode* prev = NULL;
            while(curr && n--) {
                prev = curr;
                curr = curr->next;
            }
            if(prev) prev->next = NULL;
            ans[i] = root;
        }
        
        return ans;
    }
};