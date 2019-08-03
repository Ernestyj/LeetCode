
/**
 * Merge k sorted linked lists and return it as one sorted list.
 * Analyze and describe its complexity.
 *
 * Created by DCLab on 11/6/2015.
 */
class Solution {
public:
    //时间复杂度：nklogk
    //     * 分析：假设总共有k个list，每个list的最大长度是n，那么运行时间满足递推式T(k) = 2T(k/2)+O(n*k)。
    //     * 根据主定理，可以算出算法的总复杂度是O(nklogk)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeSort(lists, 0, (int)lists.size() - 1);
    }
    ListNode* mergeSort(vector<ListNode*>& lists, int l, int r) { //归并排序范式
        if (l > r) return NULL;
        if (l == r) return lists[l];
        int m = l + (r - l) / 2;
        return mergeTwoLists(mergeSort(lists, l, m), mergeSort(lists, m + 1, r));
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
//public class MergeKSortedLists {
//
//    // Definition for singly-linked list.
//    public static class ListNode {
//        int val;
//        ListNode next;
//        ListNode(int x) { val = x; }
//    }
//
//    /**
//     * 二分法（分治法）
//     * http://blog.csdn.net/linhuanmars/article/details/19899259
//     * 时间复杂度：nklogk
//     * 分析：假设总共有k个list，每个list的最大长度是n，那么运行时间满足递推式T(k) = 2T(k/2)+O(n*k)。
//     * 根据主定理，可以算出算法的总复杂度是O(nklogk)
//     */
//    public ListNode mergeKLists(ListNode[] lists) {
//        if(lists.length==0) return null;
//        return mergeSort(lists, 0, lists.length-1);
//    }
//    private ListNode mergeSort(ListNode[] lists, int l, int r){ //归并排序范式
//        if(l>=r) return lists[l];
//        else{ //l<r
//            int m = l+(r-l)/2;
//            return mergeTwoLists(mergeSort(lists, l, m), mergeSort(lists, m+1, r));
//        }
//    }
//    private ListNode mergeTwoLists(ListNode l1, ListNode l2) {
//        if (l1 == null) return l2;
//        if (l2 == null) return l1;
//        if (l1.val<l2.val) {
//            l1.next = mergeTwoLists(l1.next, l2);
//            return l1;
//        } else {
//            l2.next = mergeTwoLists(l2.next, l1);
//            return l2;
//        }
//    }
//
//}
