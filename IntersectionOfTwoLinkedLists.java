package leetcode151_160;

/**Write a program to find the node at which the intersection of two singly linked lists begins.
 Your code should preferably run in O(n) time and use only O(1) memory.
 The linked lists must retain their original structure after the function returns.
 * Created by eugene on 16/3/14.
 */
public class IntersectionOfTwoLinkedLists {

    public class ListNode {
        int val;
        ListNode next;
        ListNode(int x) {
            val = x;
            next = null;
        }
    }

    //分别获取两链表长度并求差,长链表先跳过差数个节点,再同时遍历直到找到相同节点.
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA==null || headB==null) return null;
        if (headA==headB) return headA;
        int lenA = 1, lenB = 1;
        ListNode pA = headA, pB = headB;
        while (pA.next!=null){
            lenA++;
            pA = pA.next;
        }
        while (pB.next!=null){
            lenB++;
            pB = pB.next;
        }
        int d = lenA-lenB;
        int diff = d>=0 ? d : -d;
        pA = headA; pB = headB;
        int i = 0;
        if (d>=0) {
            while (i<diff){
                pA = pA.next;
                i++;
            }
        } else {
            while (i<diff){
                pB = pB.next;
                i++;
            }
        }
        while (pA!=null && pB!=null){
            if (pA==pB) return pA;
            pA = pA.next;
            pB = pB.next;
        }
        return null;
    }

}
