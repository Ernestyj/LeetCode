package leetcode21_30;

import java.util.*;

/**
 * Merge k sorted linked lists and return it as one sorted list.
 * Analyze and describe its complexity.
 *
 * Created by DCLab on 11/6/2015.
 */
public class MergeKSortedLists {


    // Definition for singly-linked list.
    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }


    /**
     * 二分法（分治法）
     * http://blog.csdn.net/linhuanmars/article/details/19899259
     * 时间复杂度：nklogk
     * 分析：假设总共有k个list，每个list的最大长度是n，那么运行时间满足递推式T(k) = 2T(k/2)+O(n*k)。
     * 根据主定理，可以算出算法的总复杂度是O(nklogk)
     * @param lists
     * @return
     */
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null) return null;
        return mergeSort(lists, 0, lists.length-1);
    }
    private ListNode mergeSort(ListNode[] lists, int left, int right){
        if (left>=right) return lists.length == 0 ? null : lists[left];  //TODO 注意new ListNode[0];时的边界条件
        else {
            int mid = (left+right)/2;
            return mergeTwoLists(mergeSort(lists, left, mid),
                    mergeSort(lists, mid+1, right));
        }
    }
    private ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) return l2;
        if (l2 == null) return l1;
        if (l1.val<l2.val) {
            l1.next = mergeTwoLists(l1.next, l2);
            return l1;
        } else {
            l2.next = mergeTwoLists(l2.next, l1);
            return l2;
        }
    }


    private List<Integer> array = null;
    private List<Integer> mergedArray = new ArrayList<>();
    //利用JDK排序（偷懒算法)
    public ListNode mergeKLists1(ListNode[] lists) {
        for (ListNode l : lists){
            if (l == null) continue;
            int i = 0;
            array  = new ArrayList<>();
            while (l != null){
                array.add(l.val);
                l = l.next;
            }
            mergedArray.addAll(array);
        }
        if (mergedArray.size() == 0) return null;
        Object[] result = mergedArray.toArray();
        Arrays.sort(result);
        ListNode head = new ListNode((Integer) result[0]);
        ListNode node = head;
        for (int i = 1; i < result.length; i++){
            node.next = new ListNode((Integer) result[i]);
            node = node.next;
        }
        node.next = null;
        return head;
    }


    //TODO 算法测试超时 时间复杂度：C1*C2* ... *n
    public ListNode mergeKLists2(ListNode[] lists) {
        ListNode node = null;
        for (int i = 0; i < lists.length; i++){
            node = mergeTwoLists(lists[i], node);
        }
        return node;
    }


}
