package leetcode81_90;

/**
 * Given a linked list and a value x, partition it such that all nodes less than x
 * come before nodes greater than or equal to x.
 You should preserve the original relative order of the nodes in each of the two partitions.
 For example,
 Given 1->4->3->2->5->2 and x = 3,
 return 1->2->2->4->3->5.
 * Created by DCLab on 1/7/2016.
 */
public class PartitionList {

    public static void main(String[] args) {
        System.out.println("*****RESULT*****");
    }

    // Definition for singly-linked list.
    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    /**TODO 重温 http://bangbingsyb.blogspot.com/2014/11/leetcode-partition-list.html
     * 由于不要求sort，只要求partition。可以建立一个新的链表l2。遍历原链表l1的每个节点p。
     p->val < x，保留。
     p->val >= x，从l1中移出并插入l2。
     */
    public ListNode partition(ListNode head, int x) {
        return null;
    }


    // 与上述算法复杂度一样
    // 从左往右扫描，找到第一个大于x的节点，然后再在该节点左边不断插入小于x的元素。
    public ListNode partition1(ListNode head, int x) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode p = dummy;
        ListNode cur = dummy;
        boolean foundBound = false;
        while (p!=null && p.next!=null){
            if (p.next.val >= x) {
                if (!foundBound) {
                    cur = p;
                    foundBound = true;
                }
                p = p.next;
            } else if (p.next.val < x){
                if (!foundBound){
                    p = p.next; continue;
                }
                ListNode moveNode = p.next;
                p.next = moveNode.next;

                moveNode.next = cur.next;
                cur.next = moveNode;
                cur = cur.next;
            }
        }
        return dummy.next;
    }

}
