package leetcode231_240;

import java.util.Stack;

/**Implement the following operations of a queue using stacks.
 push(x) -- Push element x to the back of queue.
 pop() -- Removes the element from in front of queue.
 peek() -- Get the front element.
 empty() -- Return whether the queue is empty.
 * Created by eugene on 16/4/26.
 */
public class ImplementQueueUsingStacks {

    class MyQueue {
        Stack<Integer> input = new Stack();
        Stack<Integer> output = new Stack();
        public void push(int x) {
            input.push(x);
        }
        public void pop() {
            peek();
            output.pop();
        }
        public int peek() {
            if (output.empty())
                while (!input.empty()) output.push(input.pop());
            return output.peek();
        }
        public boolean empty() {
            return input.empty() && output.empty();
        }
    }

    class MyQueue1 {
        Stack<Integer> s1 = new Stack<>();
        Stack<Integer> s2 = new Stack<>();
        // Push element x to the back of queue.
        public void push(int x) {
            s1.push(x);
        }
        // Removes the element from in front of queue.
        public void pop() {
            if (empty()) return;
            while (!s1.isEmpty()){
                s2.push(s1.pop());
            }
            int val = s2.pop();
            while (!s2.isEmpty()){
                s1.push(s2.pop());
            }
        }
        // Get the front element.
        public int peek() {
            if (empty()) return -1;
            while (!s1.isEmpty()){
                s2.push(s1.pop());
            }
            int val = s2.peek();
            while (!s2.isEmpty()){
                s1.push(s2.pop());
            }
            return val;
        }
        // Return whether the queue is empty.
        public boolean empty() {
            return s1.isEmpty();
        }
    }

}
