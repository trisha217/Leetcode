class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *right=head,*temp=head,*left;

        for(int i=0;i<k-1;i++)
            temp=temp->next;
        
        left=temp;

        while(temp->next)
        {
            right=right->next;
            temp=temp->next;
        }

        swap(left->val,right->val);
        return head;
    }
};