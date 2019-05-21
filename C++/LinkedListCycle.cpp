
/**Given a linked list, determine if it has a cycle in it.
 Follow up: Can you solve it without using extra space?
 * Created by eugene on 16/2/29.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};
//public class LinkedListCycle {
//
//    class ListNode {
//        int val;
//        ListNode next;
//        ListNode(int x) {
//            val = x;
//            next = null;
//        }
//    }
//
//    //使用快慢双指针,有回环则快指针会追上慢指针
//    public boolean hasCycle(ListNode head) {
//        ListNode slow = head;
//        ListNode fast = head;
//        while (fast!=null && fast.next!=null){
//            slow = slow.next;
//            fast = fast.next.next;
//            if (slow==fast) return true;
//        }
//        return false;
//    }
//
//
//    //将访问过的节点都指向一个预设的特殊节点,有回环则会访问到此特殊节点
//    public boolean hasCycle1(ListNode head) {
//        ListNode p = head;
//        ListNode dummy = new ListNode(Integer.MAX_VALUE);
//        ListNode next = null;
//        while (p!=null){
//            if (p==dummy) return true;
//            next = p.next;
//            p.next = dummy;
//            p = next;
//        }
//        return false;
//    }
//
//}
