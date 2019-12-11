
/**
 * Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists.
 *
 * Created by DCLab on 11/4/2015.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        if(l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

//public class MergeTwoSortedLists {
//
//    // Definition for singly-linked list.
//    public static class ListNode {
//        int val;
//        ListNode next;
//        ListNode(int x) { val = x; }
//    }
//
//    /**递归法
//     * 时间复杂度：O(m+n)
//     * @param l1
//     * @param l2
//     * @return
//     */
//    public ListNode mergeTwoLists1(ListNode l1, ListNode l2) {
//        return merge(l1, l2);
//    }
//    private ListNode merge(ListNode l1, ListNode l2) {
//        if (l1 == null) return l2;
//        if (l2 == null) return l1;
//        if (l1.val < l2.val) {
//            l1.next = merge(l1.next, l2);
//            return l1;
//        } else {
//            l2.next = merge(l2.next, l1);
//            return l2;
//        }
//    }
//
//}
