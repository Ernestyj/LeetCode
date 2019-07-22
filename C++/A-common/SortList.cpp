
/**Sort a linked list in O(nlogn) time using constant space complexity.
 * Created by eugene on 16/3/7.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* slow = head, *fast = head;
        while(fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head1 = head, *head2 = slow->next;
        slow->next = nullptr;
        return mergeSort(sortList(head1), sortList(head2));
    }
    ListNode* mergeSort(ListNode* h1, ListNode* h2){
        if(!h1) return h2;
        if(!h2) return h1;
        if(h1->val <= h2->val){
            h1->next = mergeSort(h1->next, h2);
            return h1;
        }else{
            h2->next = mergeSort(h1, h2->next);
            return h2;
        }
    }
};
//public class SortList {
//    public class ListNode {
//        int val;
//        ListNode next;
//        ListNode(int x) { val = x; }
//    }
//    /**
//     * O(nlogn)可以采用快速排序/归并排序/堆排序,对于链表用归并排序方便(配合合并两个有序链表).
//     */
//    public ListNode sortList(ListNode head) {
//        return mergeSort(head);
//    }
//    private ListNode mergeSort(ListNode head){
//        if (head==null || head.next==null) return head;
//        ListNode slow = head;
//        ListNode fast = head;
//        //TODO fast.next.next!=null不能漏
//        while (fast!=null && fast.next!=null && fast.next.next!=null){
//            slow = slow.next;
//            fast = fast.next.next;
//        }
//        ListNode head2 = slow.next;
//        slow.next = null;
//        ListNode l1 = mergeSort(head);
//        ListNode l2 = mergeSort(head2);
//        return mergeTwoSortedLinkedList(l1, l2);
//    }
//    private ListNode mergeTwoSortedLinkedList(ListNode l1, ListNode l2){
//        if (l1 == null) return l2;
//        if (l2 == null) return l1;
//        if (l1.val<l2.val){
//            l1.next = mergeTwoSortedLinkedList(l1.next, l2);
//            return l1;
//        } else {
//            l2.next = mergeTwoSortedLinkedList(l1, l2.next);
//            return l2;
//        }
//    }
//
//}
