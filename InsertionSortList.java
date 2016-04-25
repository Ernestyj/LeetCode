package leetcode141_150;

/**Sort a linked list using insertion sort.
 * Created by eugene on 16/3/6.
 */
public class InsertionSortList {

    public class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public ListNode insertionSortList(ListNode head) {
        if (head==null) return null;
        if (head.next==null) return head;
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode pre = head;
        ListNode curr = head.next;
        while (curr!=null) {
            if (curr.val<pre.val){
                pre.next = curr.next;
                ListNode p = dummy;
                ListNode q = dummy.next;
                while (q!=null){
                    if (curr.val<q.val){
                        p.next = curr;
                        curr.next = q;
                        break;
                    }
                    p = q;
                    q = q.next;
                }
                curr = pre.next;
            } else {
                pre = curr;
                curr = curr.next;
            }
        }
        return dummy.next;
    }

}
