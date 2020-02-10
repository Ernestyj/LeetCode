

# /**Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
#  Examples: [2,3,4] , the median is 3
#  [2,3], the median is (2 + 3) / 2 = 2.5
#
#  Design a data structure that supports the following two operations:
#  void addNum(int num) - Add a integer number from the data stream to the data structure.
#  double findMedian() - Return the median of all elements so far.
#
#  For example:
#  add(1) add(2) findMedian() -> 1.5
#  add(3)  findMedian() -> 2
#  * Created by eugene on 16/5/29.
#  */

import heapq

class MedianFinder:
    '''维护大顶堆 + 小顶堆
需要满足下面的约束条件：
1. 大顶堆中存储的元素 均不大于 小顶堆中的元素
2. 大顶堆.size() == 小顶堆.size()，或者 大顶堆.size()+1 == 小顶堆.size()
则有：
1. 大顶堆.size()+1 == 小顶堆.size()时，中位数就是小顶堆的堆顶元素
2. 大顶堆.size() == 小顶堆.size()时，中位数就是大顶堆堆顶元素与小顶堆堆顶元素的均值
    '''
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.small = []  # the smaller half of the list, min-heap with invert values 大顶堆
        self.large = []  # the larger half of the list, min heap 小顶堆

    def addNum(self, num: int) -> None:
        if len(self.small) == len(self.large):
            heapq.heappush(self.large, -heapq.heappushpop(self.small, -num))
        else:
            heapq.heappush(self.small, -heapq.heappushpop(self.large, num))

    def findMedian(self) -> float:
        if len(self.small) == len(self.large):
            return (self.large[0] - self.small[0]) / 2.0
        else:
            return self.large[0]

# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()


# public class FindMedianFromDataStream {
#
#     /**
#      * 使用两个堆,注意使用long防止溢出.
#      */
#     class MedianFinder {
#
#         PriorityQueue<Long> small, large;
#
#         public MedianFinder(){
#             small = new PriorityQueue<>();
#             large = new PriorityQueue<>();
#         }
#
#         // Adds a number into the data structure.
#         public void addNum(int num) {
#             large.add((long)num);
#             small.add(-large.poll());
#             if (large.size()<small.size())  //保持large个数总不少于small
#                 large.add(-small.poll());
#         }
#
#         // Returns the median of current data stream
#         public double findMedian() {
#             return large.size()>small.size()? large.peek() :
#                     (-small.peek()+large.peek())/2.0;
#         }
#     }
#
# // Your MedianFinder object will be instantiated and called as such:
# // MedianFinder mf = new MedianFinder();
# // mf.addNum(1);
# // mf.findMedian();
#
# }
