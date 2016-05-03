package leetcode231_240;

import java.util.ArrayList;

/**Given a singly linked list, determine if it is a palindrome.
 Follow up: Could you do it in O(n) time and O(1) space?
 * Created by eugene on 16/4/29.
 */
public class PalindromeLinkedList {

    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    //TODO 此法空间O(1),但是很容易出错. 先找到中点并同时逆转前半部分,再从中点往头/尾遍历并比较.
    public boolean isPalindrome(ListNode head) {
        if(head == null) return true;
        ListNode p1 = head;
        ListNode p2 = head;
        ListNode p3 = p1.next;
        ListNode pre = p1;
        //find mid pointer, and reverse head half part
        while(p2.next != null && p2.next.next != null) {
            p2 = p2.next.next;
            pre = p1;
            p1 = p3;
            p3 = p3.next;
            p1.next = pre;
        }
        //odd number of elements, need left move p1 one step
        if(p2.next == null) {
            p1 = p1.next;
        }
        //compare from mid to head/tail
        while(p3 != null) {
            if(p1.val != p3.val) {
                return false;
            }
            p1 = p1.next;
            p3 = p3.next;
        }
        return true;
    }


    public boolean isPalindrome1(ListNode head) {
        ArrayList<Integer> list = new ArrayList<>();
        ListNode p = head;
        while (p!=null){
            list.add(p.val);
            p = p.next;
        }
        int len = list.size();
        if (len<=1) return true;
        for (int i=0; i<len/2; i++){
            if (list.get(i).compareTo(list.get(len-i-1))!=0) return false;
        }
        return true;
    }

}
