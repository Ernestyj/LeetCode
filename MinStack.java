package leetcode151_160;

import java.util.Stack;

/**Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 push(x) -- Push element x onto stack.
 pop() -- Removes the element on top of the stack.
 top() -- Get the top element.
 getMin() -- Retrieve the minimum element in the stack.
 * Created by eugene on 16/3/13.
 */
public class MinStack {
    //链表节点引入min记录该节点以下的最小值
    class Node{
        int value;
        int min;
        Node next;
        Node(int x){
            value = x;
            min = x;
        }
    }

    private Node head;

    public void push(int x) {
        Node top = new Node(x);
        if (head!=null){
            top.next = head;
            if (head.min<top.min) top.min = head.min;
        }
        head = top;
    }

    public void pop() {
        if (head!=null) head = head.next;
    }

    public int top() {
        if (head==null) return Integer.MAX_VALUE;
        return head.value;
    }

    public int getMin() {
        if (head==null) return Integer.MAX_VALUE;
        return head.min;
    }
}
