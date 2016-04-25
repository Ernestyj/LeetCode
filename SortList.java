package leetcode141_150;

/**Sort a linked list in O(nlogn) time using constant space complexity.
 * Created by eugene on 16/3/7.
 */
public class SortList {

    public class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    /**
     * O(nlogn)可以采用快速排序/归并排序/堆排序,对于链表用归并排序方便(配合合并两个有序链表).
     * @param head
     * @return
     */
    public ListNode sortList(ListNode head) {
        return mergeSort(head);
    }
    private ListNode mergeSort(ListNode head){
        if (head==null || head.next==null) return head;
        ListNode slow = head;
        ListNode fast = head;
        //TODO fast.next.next!=null不能漏
        while (fast!=null && fast.next!=null && fast.next.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode head2 = slow.next;
        slow.next = null;
        ListNode l1 = mergeSort(head);
        ListNode l2 = mergeSort(head2);
        return mergeTwoSortedLinkedList(l1, l2);
    }
    private ListNode mergeTwoSortedLinkedList(ListNode l1, ListNode l2){
        if (l1 == null) return l2;
        if (l2 == null) return l1;
        if (l1.val<l2.val){
            l1.next = mergeTwoSortedLinkedList(l1.next, l2);
            return l1;
        } else {
            l2.next = mergeTwoSortedLinkedList(l1, l2.next);
            return l2;
        }
    }

}
