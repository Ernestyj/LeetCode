
/**Follow up for problem "Populating Next Right Pointers in Each Node".
 What if the given tree could be any binary tree? Would your previous solution still work?
 Note: You may only use constant extra space.
 * Created by eugene on 16/2/5.
 */
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() {}
    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        Node* nLevelHead = new Node(0, nullptr, nullptr, nullptr);  // dummy head of next level
        Node* pre = nLevelHead, *cur = root;
        while (cur){
            if(cur->left){
                pre->next = cur->left;
                pre = pre->next;
            }
            if(cur->right){
                pre->next = cur->right;
                pre = pre->next;
            }
            cur = cur->next;
            if(!cur){   // to the end of the level
                cur = nLevelHead->next; // cur change to next level head
                nLevelHead->next = nullptr; // reset next level head for reuse
                pre = nLevelHead;  // reset pre
            }
        }
        delete nLevelHead;
        return root;
    }
};
//public class PopulatingNextRightPointersInEachNodeII {
//    public static class TreeLinkNode {
//        int val;
//        TreeLinkNode left, right, next;
//        TreeLinkNode(int x) { val = x; }
//    }
//    //https://leetcode.com/discuss/67291/java-solution-with-constant-space 通用解法
//    public void connect(TreeLinkNode root) {
//        TreeLinkNode levelHead = new TreeLinkNode(0);
//        TreeLinkNode pre = levelHead, cur = root;
//        while (cur != null) {
//            if (cur.left != null) {
//                pre.next = cur.left;
//                pre = pre.next;
//            }
//            if (cur.right != null) {
//                pre.next = cur.right;
//                pre = pre.next;
//            }
//            cur = cur.next;
//            if (cur == null) {
//                pre = levelHead;
//                cur = levelHead.next;
//                levelHead.next = null;
//            }
//        }
//    }
//
//    /**(OJ 78%) TODO 难理解
//     * http://fisherlei.blogspot.tw/2012/12/leetcode-populating-next-right-pointers_29.html
//     * 找到规律用递归求解,类似上一题Populating Next Right Pointers in Each Node,
//     唯一的不同是每次要先找到一个第一个有效的next链接节点，并且递归的时候要先处理右子树，再处理左子树.
//     空间复杂度O(1)
//     * @param root
//     */
//    public void connect0(TreeLinkNode root) {
//        if (root==null) return;
//        TreeLinkNode p = root.next;
//        while (p!=null){
//            if (p.left!=null) {
//                p = p.left; break;
//            }
//            if (p.right!=null) {
//                p = p.right; break;
//            }
//            p = p.next;
//        }
//        if (root.right!=null) root.right.next = p;
//        if (root.left!=null) root.left.next = root.right!=null ? root.right : p;
//        connect0(root.right);
//        connect0(root.left);
//    }
//
//    /**(OJ 30%)
//     * http://www.programcreek.com/2014/06/leetcode-populating-next-right-pointers-in-each-node-ii-java/
//     * 类似二叉树层次遍历,但不再使用队列,而是将树的每一层维护成一个链表,空间复杂度O(1);
//     每次维护两层,共计4个指针:lastHead, curHead, lastCur, curPre.
//     * @param root
//     */
//    public void connect1(TreeLinkNode root) {
//        if(root == null) return;
//        TreeLinkNode lastHead = root;
//        TreeLinkNode curHead = null;
//        TreeLinkNode lastCur = null;
//        TreeLinkNode curPre = null;
//        while(lastHead!=null) {
//            lastCur = lastHead;
//            while(lastCur != null) {
//                if(lastCur.left!=null) {
//                    if(curHead == null) {
//                        curHead = lastCur.left;
//                        curPre = lastCur.left;
//                    } else {
//                        curPre.next = lastCur.left;
//                        curPre = curPre.next;
//                    }
//                }
//                if(lastCur.right!=null) {
//                    if(curHead == null) {
//                        curHead = lastCur.right;
//                        curPre = lastCur.right;
//                    } else {
//                        curPre.next = lastCur.right;
//                        curPre = curPre.next;
//                    }
//                }
//                lastCur = lastCur.next;
//            }
//            lastHead = curHead; //往下层移动
//            curHead = null;
//        }
//    }
//
//    /**类似二叉树层次遍历,使用队列,空间复杂度O(n)
//     * @param root
//     */
//    public void connect2(TreeLinkNode root) {
//        if (root==null) return;
//        Queue<TreeLinkNode> curQueue = new LinkedList<>();
//        Queue<TreeLinkNode> nextQueue = new LinkedList<>();
//        curQueue.offer(root);
//        TreeLinkNode old = null;
//        while (!curQueue.isEmpty()){
//            TreeLinkNode node = curQueue.poll();
//            if (old!=null) old.next = node;
//            old = node;
//            if (node.left!=null) nextQueue.offer(node.left);
//            if (node.right!=null) nextQueue.offer(node.right);
//            if (curQueue.isEmpty()){
//                old = null;
//                curQueue = nextQueue;
//                nextQueue = new LinkedList<>();
//            }
//        }
//    }
//
//}
