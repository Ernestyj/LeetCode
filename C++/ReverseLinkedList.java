package leetcode201_210;

/**Reverse a singly linked list.
 Hint: A linked list can be reversed either iteratively or recursively. Could you implement both?
 * Created by eugene on 16/4/2.
 */
public class ReverseLinkedList {

    // Definition for singly-linked list.
    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    //递归
    public ListNode reverseList(ListNode head) {
        if(head==null || head.next==null) return head;
        ListNode second = head.next;    //pin the second node
        head.next = null;   //TODO set first's next to be null
        ListNode rest = reverseList(second);
        second.next = head;
        return rest;
    }

    //迭代
    public ListNode reverseList1(ListNode head) {
        if (head==null) return null;
        ListNode pre = head, curr = head.next;
        while (curr!=null){
            ListNode temp = curr.next;
            curr.next = pre;
            pre = curr;
            curr = temp;
        }
        head.next = null;   //TODO 易漏
        return pre;
    }

}
