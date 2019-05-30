

/**（注意大整数）
 * You are given two linked lists representing two non-negative numbers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.

 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0), *cur = dummy;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr){
            if(l1 != nullptr){
                carry += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr){
                carry += l2->val;
                l2 = l2->next;
            }
            ListNode* node = new ListNode(carry%10);
            cur->next = node;
            carry /= 10;
            cur = node;
        }
        if(carry!=0) cur->next = new ListNode(carry);
        return dummy->next;
    }
};
//public class AddTwoNumbers {
//
//    // Definition for singly-linked list.
//    public static class ListNode {
//        int val;
//        ListNode next;
//        ListNode(int x) { val = x; }
//    }
//
//    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
//        ListNode dummy = new ListNode(0);
//        ListNode p1 = l1, p2 = l2, p3 = dummy;
//        int carry = 0;
//        while(p1!=null || p2!=null){
//            if (p1!=null){
//                carry += p1.val;
//                p1 = p1.next;
//            }
//            if (p2!=null){
//                carry += p2.val;
//                p2 = p2.next;
//            }
//            p3.next = new ListNode(carry%10);
//            p3 = p3.next;
//            carry = carry/10;
//        }
//        if (carry==1) p3.next = new ListNode(1);
//        return dummy.next;
//    }
//
//    public ListNode addTwoNumbers1(ListNode l1, ListNode l2) {
//        StringBuilder builder = new StringBuilder();
//        while (l1 != null){
//            builder.append(l1.val);
//            l1 = l1.next;
//        }
//        String first = builder.toString();
//        builder = new StringBuilder();
//        while (l2 != null){
//            builder.append(l2.val);
//            l2 = l2.next;
//        }
//        String second = builder.toString();
//
//        int diffLength = first.length() - second.length();
//        if (diffLength >= 0) second = populateZero(second, diffLength);
//        else first = populateZero(first, Math.abs(diffLength)); //TODO 注意取绝对值
//
//        builder = new StringBuilder();
//        int carryVal = 0;   //进位值
//        for (int i = 0; i < first.length(); i++){
//            int temp = first.charAt(i) - '0' + second.charAt(i) - '0' + carryVal;
//            int remainder = temp % 10;
//            carryVal = temp / 10;
//            if (i == first.length() - 1){   //最高位
//                builder.append(remainder).append(carryVal == 0 ? "" : "1");
//            } else {
//                builder.append(remainder);
//            }
//        }
//
//        String ans = builder.toString();
//        ListNode[] nodes = new ListNode[ans.length()];
//        for (int i = 0; i < ans.length(); i++){
//            nodes[i] = new ListNode(Integer.parseInt(String.valueOf(ans.charAt(i))));
//        }
//        for (int i = 0; i < ans.length(); i++){
//            if (i == ans.length() - 1) nodes[i].next = null;
//            else nodes[i].next = nodes[i + 1];
//        }
//
//        return nodes[0];
//    }
//    private String populateZero(String s, int populateLength){
//        StringBuilder builder = new StringBuilder(s);
//        for (int i = 0; i < populateLength; i++){
//            builder.append('0');
//        }
//        return builder.toString();
//    }
//
//}
