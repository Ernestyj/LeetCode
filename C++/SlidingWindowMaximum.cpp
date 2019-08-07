
/**Given an array nums, there is a sliding window of size k which is moving from the very left of
 the array to the very right. You can only see the k numbers in the window.
 Each time the sliding window moves right by one position.
 For example, Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
 Window position                Max
 ---------------               -----
 [1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 Therefore, return the max sliding window as [3,3,5,5,6,7].
 Note: You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.
 Follow up: Could you solve it in linear time?
 * Created by eugene on 16/5/3.
 */

class Solution {
public:
    //双向队列保存数字的下标，遍历整个数组，如果此时队列的首元素是 i-k 的话，表示此时窗口向右移了一步，则移除队首元素。
    // 然后比较队尾元素和将要进来的值，如果小的话就都移除，然后此时我们把队首元素加入结果中即可
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        for (int i = 0; i < nums.size(); ++i) {
            if (!q.empty() && q.front() == i - k) q.pop_front();
            while (!q.empty() && nums[q.back()] < nums[i]) q.pop_back();//(保证队列是降序的)窗口中只留下有用的值，没用的全移除掉
            q.push_back(i);
            if (i >= k - 1) res.push_back(nums[q.front()]);
        }
        return res;
    }

    //窗口内的数字是有序的，但是每次给新窗口排序又太费时了，所以最好能有一种类似二叉搜索树的结构，可以在 lgn 的时间复杂度内完成插入和删除操作，
    // 那么使用 STL 自带的 multiset 就能满足我们的需求，这是一种基于红黑树的数据结构，可以自动对元素进行排序，又允许有重复值，完美契合。
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        multiset<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k) s.erase(s.find(nums[i - k]));//若超过了k，则需要收缩l
            s.insert(nums[i]);//扩张r(插入当前值)
            if (i >= k - 1) res.push_back(*s.rbegin());//若i >= k-1，说明窗口大小正好是k，就需要将最大值加入结果 res 中
        }
        return res;
    }
};
//public class SlidingWindowMaximum {
//
//    /**https://segmentfault.com/a/1190000003903509
//     * 双端队列维护窗口(存下标). 时间O(N) 空间O(K)
//     */
//    public int[] maxSlidingWindow(int[] nums, int k) {
//        if(nums == null || nums.length == 0) return new int[0];
//        int len = nums.length;
//        int[] res = new int[len-k+1];
//        ArrayDeque<Integer> deque = new ArrayDeque<>();
//        for(int i = 0; i<len; i++){
//            // 每当新数进来时，如果发现队列头部的数的下标，是窗口最左边数的下标，则扔掉
//            if(!deque.isEmpty() && deque.peekFirst() == i-k) deque.poll();
//            // 把队列尾部所有比新数小的都扔掉，保证队列是降序的
//            while(!deque.isEmpty() && nums[deque.peekLast()]<nums[i]) deque.removeLast();
//            // 加入新数
//            deque.offerLast(i);
//            // 队列头部就是该窗口内第一大的
//            if(i+1>=k) res[i-k+1] = nums[deque.peek()];
//        }
//        return res;
//    }
//
//    //优先队列(堆)维护窗口. 时间O(NlogK) 空间O(K)
//    public int[] maxSlidingWindow1(int[] nums, int k) {
//        int len = nums.length;
//        if (len==0 || k==0) return new int[0];
//        int[] result = new int[len-k+1];
//        PriorityQueue<Integer> queue = new PriorityQueue<>(Collections.reverseOrder());
//        for (int i=0; i<k; i++){
//            queue.offer(nums[i]);
//        }
//        result[0] = queue.peek();
//        for (int i=k; i<len; i++){
//            queue.remove(nums[i-k]);
//            queue.offer(nums[i]);
//            result[i-k+1] = queue.peek();
//        }
//        return result;
//    }
//
//}
