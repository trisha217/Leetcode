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
    ListNode* getKNode(ListNode* temp, int k){
        k-=1; // subtracting the first node
        while(temp!=NULL && k>0){
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverse(ListNode* head){
        ListNode *prev = NULL, *current = head, *next = NULL;
        while(current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1 || head == NULL) return head;
        ListNode* temp = head;
        ListNode* prevNode=NULL;
        while(temp!=NULL){
            ListNode* kthNode = getKNode(temp,k);
            if(kthNode == NULL){
                if(prevNode!= NULL){
                    prevNode->next = temp;
                    break;
                }
            }
            ListNode* nextNode = kthNode->next; 
            kthNode->next = NULL;
            reverse(temp);
            if(temp == head) //reversing first K group
                head = kthNode;
            else
                prevNode->next = kthNode;
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};