package leetcode141_150;

/**Given a linked list, return the node where the cycle begins.
 If there is no cycle, return null.
 Note: Do not modify the linked list.
 Follow up: Can you solve it without using extra space?
 * Created by eugene on 16/3/1.
 */
public class LinkedListCycleII {

    class ListNode {
        int val;
        ListNode next;
        ListNode(int x) {
            val = x;
            next = null;
        }
    }

    /**
     * http://fisherlei.blogspot.co.id/2013/11/leetcode-linked-list-cycle-ii-solution.html
     * 假设链表有环，环长Y，环以外的长度是X。快慢两指针从起点出发,最后相遇在K处,设环起到到K处长度为K.
     有Y-K=X,意思是两指针相遇后再走X就回到了环的起点.
     * @param head
     * @return
     */
    public ListNode detectCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while (fast!=null && fast.next!=null){
            slow = slow.next;
            fast = fast.next.next;
            if (slow==fast) break;
        }
        if (fast==null || fast.next==null) return null; //TODO 易漏,判断无环情况
        slow = head;
        while (fast!=slow){
            slow = slow.next;
            fast = fast.next;
        }
        return slow;
    }

}
