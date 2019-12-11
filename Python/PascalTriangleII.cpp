package leetcode111_120;

import java.util.ArrayList;
import java.util.List;

/**Given an index k, return the kth row of the Pascal's triangle.
 k=5时Pascal三角如下:
 [
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
 ]
 For example, given k = 3, Return [1,3,3,1].
 Note: Could you optimize your algorithm to use only O(k) extra space?
 * Created by eugene on 16/2/7.
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        for (int i = 0; i <= rowIndex; ++i) {
            row.insert(row.begin(), 1);
            for (int j = 1; j < row.size()-1; ++j) {
                row[j] = row[j]+row[j+1];
            }
        }
        return row;
    }
};
//public class PascalTriangleII {
//
//    /**
//     * 与Pascal's Triangle类似,但是空间可以压缩为O(k).注意观察Pascal三角的特点
//     * @param rowIndex
//     * @return
//     */
//    public List<Integer> getRow(int rowIndex) {
//        List<Integer> list = new ArrayList<>();
//        if (rowIndex<0) return list;
//        for (int i=0; i<=rowIndex; i++) {
//            list.add(0, 1); //首部先插入1
//            for (int j=1; j<list.size()-1; j++) {
//                list.set(j, list.get(j) + list.get(j+1));
//            }
//        }
//        return list;
//    }
//
//}
