
/**
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 把后k个rotate到list前面去，k可以超过list本身长度。
 For example:
 Given 1->2->3->4->5->NULL and k = 2,
 return 4->5->1->2->3->NULL.
 * Created by DCLab on 12/14/2015.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k==0) return head;
        ListNode* cur = head;
        int len = 1;
        while(cur->next != nullptr){
            ++len;
            cur = cur->next;
        }
        cur->next = head;
        for (int i = 0; i < len - k % len; ++i) {
            cur = cur->next;
        }
        head = cur->next;
        cur->next = nullptr;
        return head;
    }
};
//public class RotateList {
//    public static class ListNode {
//        int val;
//        ListNode next;
//        ListNode(int x) { val = x; }
//    }
//    //因为k可以超过list本身长度，可以先首尾连起来，然后找到该断开的地方断开。
//    public ListNode rotateRight(ListNode head, int k) {
//        if (head == null || k == 0) return head;
//        ListNode p = head;
//        int len = 1;    //since p is already point to head
//        while (p.next != null) {
//            len++;
//            p = p.next;
//        }
//        p.next = head;  //form a loop
//        for (int i=0; i<len-k%len; i++) p = p.next;
//        head = p.next;  //now p points to the prev of the new head
//        p.next = null;
//        return head;
//    }
//}
