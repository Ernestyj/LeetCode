
/**Sort a linked list using insertion sort.
 * Example 1:
Input: 4->2->1->3
Output: 1->2->3->4
Example 2:
Input: -1->5->3->4->0
Output: -1->0->3->4->5
 * Created by eugene on 16/3/6.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* dummy = new ListNode(0), *cur = head, *pre = dummy;   //insert cur node between pre and cur.next
        while (cur){
            ListNode* next = cur->next; //the next node will be inserted
            while (pre->next && pre->next->val < cur->val) pre = pre->next; //find the right place to insert
            cur->next = pre->next;
            pre->next = cur;
            cur = next;

            pre = dummy;
        }
        return dummy->next;
    }
};
//public class InsertionSortList {
//    public class ListNode {
//        int val;
//        ListNode next;
//        ListNode(int x) { val = x; }
//    }
//    //虽然简洁,但更tricky
//    public ListNode insertionSortList1(ListNode head) {
//        if (head==null) return null;
//        ListNode dummy = new ListNode(0); //new starter of the sorted list
//        ListNode cur = head; //the node will be inserted
//        ListNode pre = dummy; //insert node between pre and pre.next
//        ListNode next = null; //the next node will be inserted
//        //not the end of input list
//        while(cur!=null){
//            next = cur.next;
//            //find the right place to insert
//            while( pre.next!=null && pre.next.val<cur.val ){
//                pre = pre.next;
//            }
//            //insert between pre and pre.next
//            cur.next = pre.next;
//            pre.next = cur;
//            pre = dummy;
//            cur = next;
//        }
//        return dummy.next;
//    }
//
//    //易于理解,常规思路
//    public ListNode insertionSortList(ListNode head) {
//        if (head==null) return null;
//        if (head.next==null) return head;
//        ListNode dummy = new ListNode(0);
//        dummy.next = head;
//        ListNode pre = head;
//        ListNode curr = head.next;
//        while (curr!=null) {
//            if (curr.val<pre.val){
//                pre.next = curr.next;
//                ListNode p = dummy;
//                ListNode q = dummy.next;
//                while (q!=null){
//                    if (curr.val<q.val){
//                        p.next = curr;
//                        curr.next = q;
//                        break;
//                    }
//                    p = q;
//                    q = q.next;
//                }
//                curr = pre.next;
//            } else {
//                pre = curr;
//                curr = curr.next;
//            }
//        }
//        return dummy.next;
//    }
//
//}
