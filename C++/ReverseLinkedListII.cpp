
/**
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 For example:
 Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 return 1->4->3->2->5->NULL.
 Note:
 Given m, n satisfy the following condition: 1 ≤ m ≤ n ≤ length of list.
 * Created by DCLab on 1/13/2016.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head) return nullptr;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* pre = &dummy;  // make a pointer pre as a marker for the node before reversing
        for (int i = 0; i < m - 1; ++i) pre = pre->next;
        ListNode* last = pre->next; // a pointer to the beginning of a sub-list that will be reversed
        ListNode* cur = last->next;
        for (int i = 0; i < n - m; ++i) {
            last->next = cur->next;
            cur->next = pre->next;   //cur->next = pre->next，而不是cur->next = last
            pre->next = cur;
            cur = last->next;
        }
        return dummy.next;
    }
};
//public class ReverseLinkedListII {
//    // Definition for singly-linked list.
//    public static class ListNode {
//        int val;
//        ListNode next;
//        ListNode(int x) { val = x; }
//    }
//    /**https://leetcode.com/discuss/25580/simple-java-solution-with-clear-explanation
//     * 与下面方法一致,但更简洁
//     dummy-> 1 -> 2 -> 3 -> 4 -> 5 m=2 n=4 有 pre = 1, last = 2, cur = 3
//     first reversing : dummy->1 - 3 - 2 - 4 - 5; pre = 1, last = 2, cur = 4
//     second reversing: dummy->1 - 4 - 3 - 2 - 5; pre = 1, last = 2, cur = 5 (finish)
//     */
//    public ListNode reverseBetween(ListNode head, int m, int n) {
//        if(head == null) return null;
//        ListNode dummy = new ListNode(0);
//        dummy.next = head;
//        ListNode pre = dummy; // make a pointer pre as a marker for the node before reversing
//        for(int i=0; i<m-1; i++) pre = pre.next;
//        ListNode last = pre.next; // a pointer to the beginning of a sub-list that will be reversed
//        ListNode cur = last.next;
//        for(int i=0; i<n-m; i++) {
//            last.next = cur.next;
//            cur.next = pre.next;
//            pre.next = cur;
//            cur = last.next;
//        }
//        return dummy.next;
//    }
//
//
//    /**
//     * 与Reverse Nodes In K Group思路类似，
//     * Reverse a link list between pre and next exclusively
//     * a linked list:
//     * 0->1->2->3->4->5->6
//     * |           |
//     * pre        next
//     * after call pre = reverse(pre, next)
//     * 0->3->2->1->4->5->6
//     *          |  |
//     *          pre next
//     * @param head
//     * @param m
//     * @param n
//     * @return
//     */
//    public ListNode reverseBetween1(ListNode head, int m, int n) {
//        ListNode dummy = new ListNode(0);   //因为有“放到链表首位”的操作，需要一个dummy的头节点
//        dummy.next = head;
//        ListNode pre = null;
//        ListNode cur = dummy;
//        ListNode last = null;   //where first will be doomed "last"
//        int i = 0;
//        while (i <= n){
//            if (i == m-1){  //逆转开始
//                pre = cur;
//                last = pre.next;
//                cur = last.next;
//                i+=2;
//                while (i <= n){
//                    last.next = cur.next;
//                    cur.next = pre.next;
//                    pre.next = cur;
//                    cur = last.next;
//                    i++;
//                }
//                break;
//            }
//            cur = cur.next;
//            i++;
//        }
//        return dummy.next;
//    }
//
//}
