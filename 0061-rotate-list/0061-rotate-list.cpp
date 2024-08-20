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
    ListNode* findTail(ListNode* head){
        ListNode* tail=NULL;
        ListNode* temp=head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        return temp;
    }
    int getLen(ListNode* temp){
        int len = 1;
        while(temp->next != NULL){
           len++;
           temp = temp->next;
        }
        return len; 
    }
    ListNode* findLastNode(ListNode* head,int k){
        ListNode* last = NULL;
        ListNode* temp=head;
        int cnt = 1;
        while(temp!=NULL){
            if(cnt == k){
                return temp;
            }
            cnt++;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k==0){
            return head;
        }
        int len = getLen(head);
        if(k%len == 0){
            return head;
        }
        k = k%len;
        ListNode* tail = findTail(head);
        if(head == tail){
            return head;
        }
        ListNode* temp = head;
        ListNode* newLastNode = findLastNode(head,len-k);
        tail->next = head;
        head = newLastNode->next;
        newLastNode->next = NULL;
        return head;
    }
};