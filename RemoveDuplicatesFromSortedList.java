package leetcode81_90;

/**
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 For example,
 Given 1->1->2, return 1->2.
 Given 1->1->2->3->3, return 1->2->3.
 * Created by DCLab on 1/4/2016.
 */
public class RemoveDuplicatesFromSortedList {

    public static void main(String[] args) {
        System.out.println("*****RESULT*****");
    }

    // Definition for singly-linked list.
    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }


    public ListNode deleteDuplicates(ListNode head) {
        if (head == null) return head;
        ListNode p = head;
        while (p.next != null){
            if (p.val == p.next.val){
                p.next = p.next.next;
            } else {
                p = p.next; //TODO 只有值不同时才往下走
            }
        }
        return head;
    }

    //利用RemoveDuplicatesFromSortedListII思路
    public ListNode deleteDuplicates1(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode p = dummy;
        while(p.next!=null && p.next.next!=null){
            if(p.next.val == p.next.next.val){
                int dup = p.next.val;
                p = p.next; //与RemoveDuplicatesFromSortedListII的唯一区别，多了此语句，来存储重复节点一次
                while(p.next!=null && p.next.val==dup){
                    p.next = p.next.next;
                }
            }else{
                p = p.next;
            }
        }
        return dummy.next;
    }

}
