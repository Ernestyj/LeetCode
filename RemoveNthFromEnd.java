package leetcode11_20;

/**
 * Given a linked list, remove the nth node from the end of list and return its head.

 For example,
 Given linked list: 1->2->3->4->5, and n = 2.
 After removing the second node from the end, the linked list becomes 1->2->3->5.

 Note: Given n will always be valid. Try to do this in one pass.
 *
 * Created by DCLab on 11/2/2015.
 */
public class RemoveNthFromEnd {

    public static void main(String[] args) {
        ListNode l11 = new ListNode(1);
        ListNode l12 = new ListNode(2);
        ListNode l13 = new ListNode(3);
        ListNode l14 = new ListNode(4);
        ListNode l15 = new ListNode(5);
        l11.next = l12; l12.next = l13; l13.next = l14; l14.next = l15; l15.next = null;
        ListNode node = new RemoveNthFromEnd().removeNthFromEnd(l11, 1);

        System.out.println("*****RESULT*****");
        while (node != null){
            System.out.print(node.val + " ");
            node = node.next;
        }
    }

    // Definition for singly-linked list.
    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public ListNode removeNthFromEnd(ListNode head, int n) {
        int length = 0;
        ListNode temp = head;
        while (temp != null){
            length++;
            temp = temp.next;
        }
        if (n == length) return head.next;
        temp = head;
        for (int i = 2; i <= length - n; i++){  //TODO 循环条件极易出错
            temp = temp.next;
        }
        temp.next = temp.next.next;
        return head;
    }

}
