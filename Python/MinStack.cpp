

/**Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 push(x) -- Push element x onto stack.
 pop() -- Removes the element on top of the stack.
 top() -- Get the top element.
 getMin() -- Retrieve the minimum element in the stack.
 * Created by eugene on 16/3/13.
 */
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        head = nullptr;
    }

    void push(int x) {
        Node* pTop = new Node(x);
        pTop->next = head;
        if(head != nullptr && head->min < x) pTop->min = head->min;
        head = pTop;
    }

    void pop() {
        if(head != nullptr){
            head = head->next;
        }
    }

    int top() {
        if(head != nullptr) return head->value;
        else return INT_MAX;
    }

    int getMin() {
        if(head != nullptr) return head->min;
        else return INT_MAX;
    }

    struct Node{
        int value, min;
        Node* next;
        Node(int x): value(x), min(x), next(nullptr){}
    };
    Node* head;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

//public class MinStack {
//
//    //TODO 简单
//    //链表节点引入min记录该节点以下的最小值
//    class Node{
//        int value;
//        int min;
//        Node next;
//        Node(int x){
//            value = x;
//            min = x;
//        }
//    }
//
//    private Node head;
//
//    public void push(int x) {
//        Node top = new Node(x);
//        if (head!=null){
//            top.next = head;
//            if (head.min<top.min) top.min = head.min;
//        }
//        head = top;
//    }
//
//    public void pop() {
//        if (head!=null) head = head.next;
//    }
//
//    public int top() {
//        if (head==null) return Integer.MAX_VALUE;
//        return head.value;
//    }
//
//    public int getMin() {
//        if (head==null) return Integer.MAX_VALUE;
//        return head.min;
//    }
//
//    //另一种解法:只利用一个栈 TODO 较难理解记忆,且效率慢
//    class MinStack2 {
//        int min = Integer.MAX_VALUE;
//        Stack<Integer> stack = new Stack<>();
//        public void push(int x) {
//            // only push the old minimum value when the current minimum value changes
//            // after pushing the new value x
//            if(x <= min){
//                stack.push(min);
//                min = x;
//            }
//            stack.push(x);
//        }
//
//        public void pop() {
//            // if pop operation could result in the changing of the current minimum value,
//            // pop twice and change the current minimum value to the last minimum value.
//            if(stack.peek()==min) {
//                stack.pop();
//                min = stack.peek();
//                stack.pop();
//            }else{
//                stack.pop();
//            }
//            if(stack.empty()){
//                min=Integer.MAX_VALUE;
//            }
//        }
//
//        public int top() {
//            return stack.peek();
//        }
//
//        public int getMin() {
//            return min;
//        }
//    }
//}
