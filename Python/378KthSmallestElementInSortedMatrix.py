
# /**
#  * Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
# Note that it is the kth smallest element in the sorted order, not the kth distinct element.
# Example:
# matrix = [
#    [ 1,  5,  9],
#    [10, 11, 13],
#    [12, 13, 15]
# ],
# k = 8,
# return 13.
# Note:
# You may assume k is always valid, 1 ≤ k ≤ n2.
#  难点在于数组并不是蛇形有序的，意思是当前行的最后一个元素并不一定会小于下一行的首元素
#  */

'''
根据堆的算法，可以实现改进，不用把每个元素都进堆，只需要把“最可能是最小值”的进堆即可。也就是说我们每次进堆的元素只要包括下一个最小的元素即可。
把左上角最小的元素和其索引进堆，然后把堆里的元素进行一个遍历，每次把元素的右边的元素进堆。当是第一列元素的时候，把这个元素下面的元素也进堆。
'''
import heapq
class Solution(object):
    def kthSmallest(self, matrix, k):
        m, n = len(matrix), len(matrix[0])
        q = [(matrix[0][0], 0, 0)]  # 左上角最小的元素
        ans = 0
        for _ in range(k):
            ans, i, j = heapq.heappop(q)
            if j == 0 and i + 1 < m:    # 当是第一列元素的时候，把这个元素下面的元素也进堆
                heapq.heappush(q, (matrix[i + 1][j], i + 1, j))
            if j + 1 < n:   # 把元素的右边的元素进堆
                heapq.heappush(q, (matrix[i][j + 1], i, j + 1))
        return ans

class Solution1(object):    # 小顶堆
    def kthSmallest(self, matrix, k):
        nums = []
        for line in matrix:
            nums.extend(line)
        heapq.heapify(nums)
        res = 0
        for i in range(k):
            res = heapq.heappop(nums)
        return res

# class Solution {
# public:
#     /**
#      * 二分法：左上角的数字一定是最小的，而右下角的数字一定是最大的
#      *
# [1 2
# 12 100], k = 3
# 开始 left = 1, right = 100, mid = 50, 遍历完 cnt = 3，此时 right 更新为 50
# 此时 left = 1, right = 50, mid = 25, 遍历完之后 cnt = 3, 此时 right 更新为 25
# 此时 left = 1, right = 25, mid = 13, 遍历完之后 cnt = 3, 此时 right 更新为 13
# 此时 left = 1, right = 13, mid = 7, 遍历完之后 cnt = 2, 此时 left 更新为 8
# 此时 left = 8, right = 13, mid = 10, 遍历完之后 cnt = 2, 此时 left 更新为 11
# 此时 left = 11, right = 12, mid = 11, 遍历完之后 cnt = 2, 此时 left 更新为 12
# 循环结束，left 和 right 均为 12，任意返回一个即可。
#
# 本解法的整体时间复杂度为 O(nlgn*lgX)，其中X为最大值和最小值的差值
#      */
#     int kthSmallest(vector<vector<int>>& matrix, int k) {
#         int l = matrix[0][0], r = matrix.back().back();
#         while (l <= r) {
#             int m = l + (r - l) / 2, cnt = 0;
#             for (int i = 0; i < matrix.size(); ++i) {//如果目标数在比该行的尾元素大，则 upper_bound 返回该行元素的个数，如果目标数比该行首元素小，则返回0
#                 cnt += upper_bound(matrix[i].begin(), matrix[i].end(), m) - matrix[i].begin();
#             }//我们遍历完所有的行可以找出中间数是第几小的数，然后k比较，进行二分查找，left 和 right 最终会相等，并且会变成数组中第k小的数字
#             if (cnt < k) l = m + 1;
#             else r = m-1;
#         }
#         return l;
#     }
#
#     int kthSmallest(vector<vector<int>>& matrix, int k) {//大顶堆
#         priority_queue<int> q;
#         for (int i = 0; i < matrix.size(); ++i) {
#             for (int j = 0; j < matrix[i].size(); ++j) {
#                 q.emplace(matrix[i][j]);
#                 if (q.size() > k) q.pop();
#             }
#         }
#         return q.top();
#     }
# };