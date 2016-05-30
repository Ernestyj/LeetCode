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

    //虽然简洁,但更tricky
    public ListNode insertionSortList1(ListNode head) {
        if (head==null) return null;
        ListNode dummy = new ListNode(0); //new starter of the sorted list
        ListNode cur = head; //the node will be inserted
        ListNode pre = dummy; //insert node between pre and pre.next
        ListNode next = null; //the next node will be inserted
        //not the end of input list
        while(cur!=null){
            next = cur.next;
            //find the right place to insert
            while( pre.next!=null && pre.next.val<cur.val ){
                pre = pre.next;
            }
            //insert between pre and pre.next
            cur.next = pre.next;
            pre.next = cur;
            pre = dummy;
            cur = next;
        }
        return dummy.next;
    }

    //易于理解,常规思路
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
