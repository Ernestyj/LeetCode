
/**
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 For example,
 Given 1->1->2, return 1->2.
 Given 1->1->2->3->3, return 1->2->3.
 * Created by DCLab on 1/4/2016.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* deleteDuplicates1(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        head->next = deleteDuplicates(head->next);
        return head->val == head->next->val ? head->next : head;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* p = head;
        while(p->next != nullptr){
            if(p->val == p->next->val){
                p->next = p->next->next;
            }else{
                p = p->next;
            }
        }
        return head;
    }
};
//public class RemoveDuplicatesFromSortedList {
//    // Definition for singly-linked list.
//    public static class ListNode {
//        int val;
//        ListNode next;
//        ListNode(int x) { val = x; }
//    }
//
//    //简洁 递归 https://leetcode.com/discuss/37323/3-line-java-recursive-solution
//    public ListNode deleteDuplicates(ListNode head) {
//        if(head == null || head.next == null)return head;
//        head.next = deleteDuplicates(head.next);
//        return head.val==head.next.val? head.next : head;
//    }
//
//    //TODO 记忆此方法
//    public ListNode deleteDuplicates1(ListNode head) {
//        if (head == null) return head;
//        ListNode p = head;
//        while (p.next != null){
//            if (p.val == p.next.val){
//                p.next = p.next.next;
//            } else {
//                p = p.next; //TODO 只有值不同时才往下走
//            }
//        }
//        return head;
//    }
//
//    //利用RemoveDuplicatesFromSortedListII思路
//    public ListNode deleteDuplicates2(ListNode head) {
//        ListNode dummy = new ListNode(0);
//        dummy.next = head;
//        ListNode p = dummy;
//        while(p.next!=null && p.next.next!=null){
//            if(p.next.val == p.next.next.val){
//                int dup = p.next.val;
//                p = p.next; //与RemoveDuplicatesFromSortedListII的唯一区别，多了此语句，来存储重复节点一次
//                while(p.next!=null && p.next.val==dup){
//                    p.next = p.next.next;
//                }
//            }else{
//                p = p.next;
//            }
//        }
//        return dummy.next;
//    }
//
//}
