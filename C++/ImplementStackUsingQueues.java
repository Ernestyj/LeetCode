package leetcode221_230;

import java.util.LinkedList;

/**Implement the following operations of a stack using queues.
 push(x) -- Push element x onto stack.
 pop() -- Removes the element on top of the stack.
 top() -- Get the top element.
 empty() -- Return whether the stack is empty.
 Notes:
 You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
 Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
 You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
 * Created by eugene on 16/4/19.
 */
public class ImplementStackUsingQueues {

    //仅借助一个队列,但是push操作慢
    class MyStack {

        LinkedList<Integer> q;
        public MyStack() {
            q = new LinkedList<>();
        }

        // Push element x onto stack.
        public void push(int x) {
            q.offer(x);
            for (int i=0; i<q.size()-1; i++) q.offer(q.poll());
        }

        // Removes the element on top of the stack.
        public void pop() {
            q.poll();
        }

        // Get the top element.
        public int top() {
            return q.peek();
        }

        // Return whether the stack is empty.
        public boolean empty() {
            return q.isEmpty();
        }
    }

}
