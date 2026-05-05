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
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null || k == 0) return head;

        // 1. Find the length and the actual last node
        ListNode oldTail = head;
        int length = 1;
        while (oldTail.next != null) {
            oldTail = oldTail.next;
            length++;
        }

        // 2. Connect tail to head to make it a circle
        oldTail.next = head;

        // 3. Find the new tail: (length - k % length - 1) steps from start
        ListNode newTail = head;
        for (int i = 0; i < length - (k % length) - 1; i++) {
            newTail = newTail.next;
        }

        // 4. New head is after the new tail, then break the link
        ListNode newHead = newTail.next;
        newTail.next = null;

        return newHead;
    }
}