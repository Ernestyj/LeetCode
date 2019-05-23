package leetcode201_210;

import java.util.List;

/**Remove all elements from a linked list of integers that have value val.
 Example
 Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 Return: 1 --> 2 --> 3 --> 4 --> 5
 * Created by eugene on 16/4/1.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) return nullptr;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};

//public class RemoveLinkedListElements {
//
//    public class ListNode {
//        int val;
//        ListNode next;
//        ListNode(int x) { val = x; }
//    }
//
//    //类似RemoveDuplicatesFromSortedList
//    public ListNode removeElements(ListNode head, int val) {
//        if (head==null) return null;
//        head.next = removeElements(head.next, val);
//        return head.val==val? head.next : head;
//    }
//
//    //标准删除:dummy+pre+cur
//    public ListNode removeElements1(ListNode head, int val) {
//        ListNode dummy = new ListNode(0);
//        dummy.next = head;
//        ListNode pre = dummy;
//        ListNode p = head;
//        while (p!=null){
//            if (p.val==val) {
//                pre.next = p.next;
//                p = pre.next;
//            } else {
//                pre = p;
//                p = p.next;
//            }
//        }
//        return dummy.next;
//    }
//
//}
