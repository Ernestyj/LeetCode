package leetcode231_240;

import java.util.ArrayList;

/**Given a singly linked list, determine if it is a palindrome.
 Follow up: Could you do it in O(n) time and O(1) space?
 * Created by eugene on 16/4/29.
 */
public class PalindromeLinkedList {

    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    /**图 https://leetcode.com/discuss/78152/java-easy-to-understand
     * 先找到重点,逆转后半部分,比较
     * @param head
     * @return
     */
    public boolean isPalindrome(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;
        while(fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        slow = reverseList(slow);
        while(slow != null && head.val == slow.val) {
            head = head.next;
            slow = slow.next;
        }
        return slow == null;
    }
    private ListNode reverseList(ListNode head) {
        if(head==null || head.next==null) return head;
        ListNode second = head.next;    //pin the second node
        ListNode rest = reverseList(second);
        second.next = head;
        head.next = null;   //TODO set first's next to be null
        return rest;
    }

}
