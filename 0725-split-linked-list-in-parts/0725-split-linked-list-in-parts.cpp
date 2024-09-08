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
        ListNode* temp=head;
        ListNode* prev=nullptr;
        int count=0;
        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }
        int remainder=count%k;
        int node=count/k;
        temp=head;
        int extra=k-remainder;
        vector<ListNode*> ans;
        while(temp!=nullptr){
            ans.push_back(temp);
            int j=0;
            if(remainder>0){
                j=1;
            }
            for(int i=0;i<node+j;i++){
                prev=temp;
                temp=temp->next;
            }
            remainder--;
            prev->next=nullptr;
        }
        if(node==0){
            while(extra>0){
                ans.push_back(temp);
                extra--;
            }
        }
        return ans;
    }
};