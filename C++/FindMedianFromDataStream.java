package leetcode291_300;

import java.util.Iterator;
import java.util.PriorityQueue;

/**Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
 Examples: [2,3,4] , the median is 3
 [2,3], the median is (2 + 3) / 2 = 2.5

 Design a data structure that supports the following two operations:
 void addNum(int num) - Add a integer number from the data stream to the data structure.
 double findMedian() - Return the median of all elements so far.

 For example:
 add(1) add(2) findMedian() -> 1.5
 add(3)  findMedian() -> 2
 * Created by eugene on 16/5/29.
 */
public class FindMedianFromDataStream {

    /**
     * 使用两个堆,注意使用long防止溢出.
     */
    class MedianFinder {

        PriorityQueue<Long> small, large;

        public MedianFinder(){
            small = new PriorityQueue<>();
            large = new PriorityQueue<>();
        }

        // Adds a number into the data structure.
        public void addNum(int num) {
            large.add((long)num);
            small.add(-large.poll());
            if (large.size()<small.size())  //保持large个数总不少于small
                large.add(-small.poll());
        }

        // Returns the median of current data stream
        public double findMedian() {
            return large.size()>small.size()? large.peek() :
                    (-small.peek()+large.peek())/2.0;
        }
    }

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf = new MedianFinder();
// mf.addNum(1);
// mf.findMedian();

}
