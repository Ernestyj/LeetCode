

/**Implement the following operations of a queue using stacks.
 push(x) -- Push element x to the back of queue.
 pop() -- Removes the element from in front of queue.
 peek() -- Get the front element.
 empty() -- Return whether the queue is empty.
 * Created by eugene on 16/4/26.
 */
class MyQueue {
public:
    MyQueue() {}
    void push(int x) {
        _new.push(x);
    }
    int pop() {
        shiftStack();
        int val = _old.top(); _old.pop();
        return val;
    }
    int peek() {
        shiftStack();
        return _old.top();
    }
    bool empty() {
        return _old.empty() && _new.empty();
    }

    void shiftStack() {
        if (!_old.empty()) return;
        while (!_new.empty()) {
            _old.push(_new.top());
            _new.pop();
        }
    }
private:
    stack<int> _old, _new;
};

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> temp;
        while(!s.empty()){
            temp.push(s.top());
            s.pop();
        }
        s.push(x);
        while (!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int v = s.top();
        s.pop();
        return v;
    }

    /** Get the front element. */
    int peek() {
        return s.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }
private:
    stack<int> s;
};
//public class ImplementQueueUsingStacks {
//
//    class MyQueue {
//        Stack<Integer> input = new Stack();
//        Stack<Integer> output = new Stack();
//        public void push(int x) {
//            input.push(x);
//        }
//        public void pop() {
//            peek();
//            output.pop();
//        }
//        public int peek() {
//            if (output.empty())//TODO 易漏
//                while (!input.empty()) output.push(input.pop());
//            return output.peek();
//        }
//        public boolean empty() {
//            return input.empty() && output.empty();
//        }
//    }
//
//    class MyQueue1 {
//        Stack<Integer> s1 = new Stack<>();
//        Stack<Integer> s2 = new Stack<>();
//        // Push element x to the back of queue.
//        public void push(int x) {
//            s1.push(x);
//        }
//        // Removes the element from in front of queue.
//        public void pop() {
//            if (empty()) return;
//            while (!s1.isEmpty()){
//                s2.push(s1.pop());
//            }
//            int val = s2.pop();
//            while (!s2.isEmpty()){
//                s1.push(s2.pop());
//            }
//        }
//        // Get the front element.
//        public int peek() {
//            if (empty()) return -1;
//            while (!s1.isEmpty()){
//                s2.push(s1.pop());
//            }
//            int val = s2.peek();
//            while (!s2.isEmpty()){
//                s1.push(s2.pop());
//            }
//            return val;
//        }
//        // Return whether the queue is empty.
//        public boolean empty() {
//            return s1.isEmpty();
//        }
//    }
//
//}
