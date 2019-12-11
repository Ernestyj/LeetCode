
/**
 * Given a linked list and a value x, partition it such that all nodes less than x
 * come before nodes greater than or equal to x.
 You should preserve the original relative order of the nodes in each of the two partitions.
 For example,
 Given 1->4->3->2->5->2 and x = 3,
 return 1->2->2->4->3->5.
 * Created by DCLab on 1/7/2016.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1(0), dummy2(0);
        ListNode* p1 = &dummy1, *p2 = &dummy2;
        while (head){
            if(head->val<x) {
                p1->next = head;
                p1 = p1->next;
            }
            else {
                p2->next = head;
                p2 = p2->next;
            }
            head = head->next;
        }
        p1->next = dummy2.next;
        p2->next = nullptr; //TODO avoid cycle in linked list. otherwise u will get TLE.
        return dummy1.next;
    }
};
//public class PartitionList {
//    // Definition for singly-linked list.
//    public static class ListNode {
//        int val;
//        ListNode next;
//        ListNode(int x) { val = x; }
//    }
//    /**https://leetcode.com/discuss/22895/concise-java-code-with-explanation-one-pass
//     * maintain two queues, the first one stores all nodes with val less than x ,
//     and the second queue stores all the rest nodes. Then concat these two queues.
//     Remember to set the tail of second queue a null next, or u will get TLE.
//     */
//    public ListNode partition(ListNode head, int x) {
//        ListNode dummy1 = new ListNode(0), dummy2 = new ListNode(0);
//        ListNode curr1 = dummy1, curr2 = dummy2;    //current tails of the two queues;
//        while (head!=null){
//            if (head.val<x) {
//                curr1.next = head;
//                curr1 = head;
//            }else {
//                curr2.next = head;
//                curr2 = head;
//            }
//            head = head.next;
//        }
//        curr2.next = null;  //TODO avoid cycle in linked list. otherwise u will get TLE.
//        curr1.next = dummy2.next;
//        return dummy1.next;
//    }
//
//    // 从左往右扫描，找到第一个大于x的节点，然后再在该节点左边不断插入小于x的元素。
//    public ListNode partition1(ListNode head, int x) {
//        ListNode dummy = new ListNode(0);
//        dummy.next = head;
//        ListNode p = dummy;
//        ListNode cur = dummy;
//        boolean foundBound = false;
//        while (p!=null && p.next!=null){
//            if (p.next.val >= x) {
//                if (!foundBound) {
//                    cur = p;
//                    foundBound = true;
//                }
//                p = p.next;
//            } else if (p.next.val < x){
//                if (!foundBound){
//                    p = p.next; continue;
//                }
//                ListNode moveNode = p.next;
//                p.next = moveNode.next;
//
//                moveNode.next = cur.next;
//                cur.next = moveNode;
//                cur = cur.next;
//            }
//        }
//        return dummy.next;
//    }
//
//}
