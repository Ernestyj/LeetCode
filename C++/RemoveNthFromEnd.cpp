
/**
 * Given a linked list, remove the nth node from the end of list and return its head.

 For example,
 Given linked list: 1->2->3->4->5, and n = 2.
 After removing the second node from the end, the linked list becomes 1->2->3->5.

 Note: Given n will always be valid. Try to do this in one pass.
 *
 * Created by DCLab on 11/2/2015.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    //dummy->1->2->3->4->5
    //  s          f
    //             s       f
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy, *fast = dummy;
        for (int i = 1; i <= n + 1; ++i) {  //TODO 注意边界是n+1，为了让slow停止位置为deleting node前一个位置
            fast = fast->next;
        }
        while(fast != nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy, *fast = dummy;
        for(int i = 0; i<n; ++i){
            fast = fast->next;
        }
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};
//public class RemoveNthFromEnd {
//
//    // Definition for singly-linked list.
//    public static class ListNode {
//        int val;
//        ListNode next;
//        ListNode(int x) { val = x; }
//    }
//
//    //one pass
//    public ListNode removeNthFromEnd(ListNode head, int n) {
//        ListNode dummy = new ListNode(0);
//        dummy.next = head;
//        ListNode slow = dummy, fast = dummy;
//        //Move fast in front so that the gap between slow and fast becomes n
//        for(int i=1; i<=n+1; i++) { //TODO 注意边界
//            fast = fast.next;
//        }
//        //Move fast to the end, maintaining the gap
//        while(fast != null) {
//            slow = slow.next;
//            fast = fast.next;
//        }
//        //Skip the desired node
//        slow.next = slow.next.next;
//        return dummy.next;
//    }
//
//    //two pass
//    public ListNode removeNthFromEnd1(ListNode head, int n) {
//        int length = 0;
//        ListNode temp = head;
//        while (temp != null){
//            length++;
//            temp = temp.next;
//        }
//        if (n == length) return head.next;
//        temp = head;
//        for (int i = 2; i <= length - n; i++){  //TODO 循环条件极易出错
//            temp = temp.next;
//        }
//        temp.next = temp.next.next;
//        return head;
//    }
//
//}
