package leetcode21_30;

/**
 * Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists.
 *
 * Created by DCLab on 11/4/2015.
 */
public class MergeTwoSortedLists {

    public static void main(String[] args) {
        ListNode l11 = new ListNode(2);
        ListNode l12 = new ListNode(3);
        ListNode l13 = new ListNode(5);
        l11.next = l12; l12.next = l13; l13.next = null;
//        ListNode l21 = new ListNode(2);
//        ListNode l22 = new ListNode(4);
//        ListNode l23 = new ListNode(9);
//        l21.next = l22; l22.next = l23; l23.next = null;
        ListNode l21 = null;

//        ListNode node = new MergeTwoSortedLists().mergeTwoLists(l11, l21);
        ListNode node = new MergeTwoSortedLists().mergeTwoLists1(l11, l21);
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

    //TODO 下述方法可以引入dummy头结点来简化
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode node1 = l1;
        ListNode node2 = l2;
        ListNode mergedHead;
        ListNode mergedNode = null;
        if (l1 == null && l2 == null){  //TODO 易漏
            return null;
        } else if (l1 == null || (l2 != null && l1.val > l2.val)){  //TODO 易漏l2 != null
            mergedNode = l2;
            node2 = node2.next;
        } else if (l2 == null || (l1 != null && l1.val <= l2.val)) {    //TODO 易漏l1 != null，不过此处省略也没错
            mergedNode = l1;
            node1 = node1.next;
        }
        mergedHead = mergedNode;
        while (node2 != null){
            if (node1 == null || node1.val > node2.val){
                mergedNode.next = node2;
                node2 = node2.next;
            } else {
                mergedNode.next = node1;
                node1 = node1.next;
            }
            mergedNode = mergedNode.next;
        }
        while (node1 != null){
            mergedNode.next = node1;
            mergedNode = mergedNode.next;
            node1 = node1.next;
        }
        mergedNode.next = null;

        return mergedHead;
    }

    /**TODO 重温
     * 递归法
     * 时间复杂度：与上述传统方法一样 ？？？
     * @param l1
     * @param l2
     * @return
     */
    public ListNode mergeTwoLists1(ListNode l1, ListNode l2) {
        return merge(l1, l2);
    }
    private ListNode merge(ListNode l1, ListNode l2) {
        if (l1 == null) return l2;
        if (l2 == null) return l1;
        if (l1.val < l2.val) {
            l1.next = merge(l1.next, l2);
            return l1;
        } else {
            l2.next = merge(l2.next, l1);
            return l2;
        }
    }

}
