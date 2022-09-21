/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode swapNodes(ListNode head, int k) {
        ListNode cur = head;
        int cnt = 0;
        ListNode val1 = new ListNode(0);
        ListNode val2 = new ListNode(0);
        while(cur!=null){
            cnt++;
            if(cnt == k){
                val1 = cur;
            }
            cur = cur.next;
        }
        if(cnt<k){
            return head;
        }
        //System.out.println(cnt);
        int p = cnt-k+1;
        //System.out.println(p);
        cnt = 0;
        cur = head;
        while(cur!=null){
            cnt++;
            if(cnt == p){
                val2 = cur;
            }
            cur = cur.next;
        }
        //swapping
        int temp;
        temp = val1.val;
        val1.val = val2.val;
        val2.val = temp;
        return head;
    }
}