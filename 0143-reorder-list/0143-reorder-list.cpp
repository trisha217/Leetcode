class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr)
            return;
        ListNode * slow = head;
        ListNode * fast = head->next;
        int count = 1;
        //find the middle
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            ++count;
        }
        //this ensures that in case list length is odd, the first half is longer than the second
        ListNode * tmp = slow->next;
        slow->next = nullptr;
        slow = tmp;
        
        //reverse the second part of the list
        ListNode * prev = nullptr;
        ListNode * nxt;
        while (slow != nullptr)
        {
            nxt = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nxt;
        }

        //join the two lists
        ListNode * cur = head;
        int tmpC = count;
        while (cur != nullptr && prev != nullptr)
        {
            ListNode * tmp = cur->next;
            ListNode * tmp2 = prev->next;
            cur->next = prev;
            prev->next = tmp;
            cur = tmp;
            prev = tmp2;
        }
    }
};