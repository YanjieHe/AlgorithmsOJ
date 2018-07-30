/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null) {
            return head;
        } else {
            ListNode prev = head;
            ListNode current = head.next;
            while(current != null) {
                if(prev.val == current.val) {
                    prev.next = current.next;
                    current = current.next;
                } else {
                    prev = current;
                    current = current.next;
                }
            }
            return head;
        }
    }
}
