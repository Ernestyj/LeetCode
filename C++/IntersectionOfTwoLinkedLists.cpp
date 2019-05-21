

/**Write a program to find the node at which the intersection of two singly linked lists begins.
 Your code should preferably run in O(n) time and use only O(1) memory.
 The linked lists must retain their original structure after the function returns.
 * Created by eugene on 16/3/14.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) return nullptr;
        ListNode* a = headA, *b = headB;
        while (a != b){
            a = a->next;
            b = b->next;
            if(a == b) return a;
            if(a == nullptr) a = headB;
            if(b == nullptr) b = headA;
        }
        return a;//TODO 不能是 return nullptr, 因为 headA == headB 的情况
    }
};

//public class IntersectionOfTwoLinkedLists {
//
//    public class ListNode {
//        int val;
//        ListNode next;
//        ListNode(int x) {
//            val = x;
//            next = null;
//        }
//    }
//
//    //简洁,tricky,易理解
//    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
//        if (headA==null || headB==null) return null;
//        ListNode a = headA;
//        ListNode b = headB;
//        while (a!=b) {
//            a = a.next;
//            b = b.next;
//            if (a==b) return a; //TODO in case a==b==null 无交叉情况
//            if (a==null) a = headB;
//            if (b==null) b = headA;
//        }
//        return a;
//    }
//
//
//    //易于理解:分别获取两链表长度并求差,长链表先跳过差数个节点,再同时遍历直到找到相同节点.
//    public ListNode getIntersectionNode1(ListNode headA, ListNode headB) {
//        if (headA == null || headB == null) return null;
//        int lenA = length(headA), lenB = length(headB);
//        // move headA and headB to the same start point
//        while (lenA > lenB) {
//            headA = headA.next;
//            lenA--;
//        }
//        while (lenA < lenB) {
//            headB = headB.next;
//            lenB--;
//        }
//        // find the intersection until end
//        while (headA != headB) {
//            headA = headA.next;
//            headB = headB.next;
//        }
//        return headA;
//    }
//    private int length(ListNode node) {
//        int length = 0;
//        while (node != null) {
//            node = node.next;
//            length++;
//        }
//        return length;
//    }
//
//}
