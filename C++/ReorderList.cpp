
/**Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 You must do this in-place without altering the nodes' values.
 For example, Given {1,2,3,4}, reorder it to {1,4,2,3}.
 * Created by eugene on 16/3/2.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* l2 = slow->next, *l1 = head;
        slow->next = nullptr;   //TODO 易漏
        l2 = reverse(l2);
        merge(l1, l2);
    }
    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* pre = head, *cur = head->next;
        while(cur){
            ListNode* t = cur->next;
            cur->next = pre;
            pre = cur;
            cur = t;
        }
        head->next = nullptr;
        return pre;
    }
    void merge(ListNode* l1, ListNode* l2){ //l2长度<=l1长度
        while(l2){
            ListNode* next1 = l1->next, *next2 = l2->next;
            l1->next = l2;
            l2->next = next1;

            l1 = next1;
            l2 = next2;
        }
    }
};
//public class ReorderList {
//    static class ListNode {
//        int val;
//        ListNode next;
//        ListNode(int x) { val = x; }
//    }
//    /**
//     * 使用快慢指针先将链表分成两半,逆转后半段链表,再交叉合并.
//     * http://www.programcreek.com/2013/12/in-place-reorder-a-singly-linked-list-in-java/
//     */
//    public void reorderList(ListNode head) {
//        if (head==null || head.next==null) return;
//        ListNode slow = head, fast = head;
//        while (fast.next!=null && fast.next.next!=null){
//            slow = slow.next;
//            fast = fast.next.next;
//        }
//        ListNode l2 = slow.next;
//        slow.next = null;
//        l2 = reverse(l2);
//        crossMerge(head, l2);
//    }
//    private ListNode reverse(ListNode head){//TODO 用递归法会栈溢出
//        if (head==null || head.next==null) return head;
//        ListNode pre = head;
//        ListNode curr = head.next;
//        while (curr!=null){
//            ListNode temp = curr.next;
//            curr.next = pre;
//            pre = curr;
//            curr = temp;
//        }
//        head.next = null;
//        return pre;
//    }
//    //链表l1/l2长度一致,交叉合并
//    private void crossMerge(ListNode l1, ListNode l2){
//        ListNode p1 = l1, p2 = l2;
//        while (p2!=null){
//            ListNode temp1 = p1.next, temp2 = p2.next;
//            p1.next = p2;
//            p2.next = temp1;
//            p1 = temp1;
//            p2 = temp2;
//        }
//    }
//
//}
