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
    int gcd(int a,  int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head->next) return head;
        ListNode *ptr = head;
        ListNode *prev = head;

        map<int, int> map;
        int i{};
        while(ptr->next) {
            map[i++] = gcd(ptr->val, ptr->next->val);
            ptr = ptr->next;
        }
        i = 0;
        ptr = head->next;
        while(ptr) {
            ListNode *newNode = new ListNode(map[i++]);
            newNode->next = ptr;
            prev->next = newNode;
            prev = ptr;
            ptr = ptr->next;
        }

        return head;
    }
};