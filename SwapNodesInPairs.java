package leetcode21_30;

/**
 * Given a linked list, swap every two adjacent nodes and return its head.

 For example,
 Given 1->2->3->4, you should return the list as 2->1->4->3.

 Your algorithm should use only constant space.
 You may not modify the values in the list, only nodes itself can be changed.
 *
 * Created by Eugene on 11/7/2015.
 */
public class SwapNodesInPairs {

    public static void main(String[] args) {
        ListNode l11 = new ListNode(1);
        ListNode l12 = new ListNode(2);
        ListNode l13 = new ListNode(3);
        ListNode l14 = new ListNode(4);
        ListNode l15 = new ListNode(5);
        l11.next = l12; l12.next = l13; l13.next = l14; l14.next = l15; l15.next = null;

        ListNode node = new SwapNodesInPairs().swapPairs(l11);
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

    public ListNode swapPairs(ListNode head) {
        if (head == null) return null;
        ListNode pre = null;
        ListNode first = head;
        ListNode second = head.next;
        if (second == null) return first;   //TODO 当只有一个元素时
        swap(pre, first, second);
        ListNode resultHead = second;
        pre = first;
        first = first.next;
        if (first != null)  second = first.next;
        while (first != null){
            swap(pre, first, second);
            pre = first;
            first = first.next;
            if (first != null)  second = first.next;
        }
        return resultHead;
    }
    private void swap(ListNode pre, ListNode first, ListNode second){
        if (second == null) return;
        first.next = second.next;
        second.next = first;
        if (pre != null) pre.next = second;
    }

}
