
/**Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?
 Hint: Expected runtime complexity is in O(log n) and the input is sorted.
 * Created by eugene on 16/5/18.
 */
class Solution {
public:
    int hIndex(vector<int>& citations) {//标准二分法，O(log n)
        int N = citations.size(), l = 0, r = N-1, m = 0;
        while (l<=r){
            m = l+(r-l)/2;
            if(citations[m]<N-m) l = m+1;   // 如果该点是有效的H指数，则最大H指数一定在右边
            else if(citations[m]==N-m) return N-m;
            else r = m-1;   //// 否则最大H指数在左边
        }
        return N-l; // TODO 注意返回值是N-l, N-l是l点的H指数
    }
};
//public class HIndexII {
//    /**
//     * https://segmentfault.com/a/1190000003794831
//     * 二分法, O(log n)
//     */
//    public int hIndex(int[] citations) {
//        int N = citations.length;
//        if(N==0) return 0;
//        int l = 0, r = citations.length-1;
//        while(l <= r){
//            int m = (l+r)/2;
//            if(citations[m] < N-m){ // 如果该点是有效的H指数，则最大H指数一定在右边
//                l = m+1;
//            } else if (citations[m] == N-m)
//                return N-m;
//            else {    // 否则最大H指数在左边
//                r = m-1;
//            }
//        }
//        return N-l; // TODO 注意返回值是N-l, N-l是l点的H指数
//    }
//
//    //O(n)
//    public int hIndex1(int[] citations) {
//        int N = citations.length;
//        if (N<1) return 0;
//        int h = 0;
//        for (int i=0; i<N; i++){
//            int currH = Math.min(citations[i], N-i);  //得到当前的H指数,不是citations[i]就是len-i
//            if(currH>h) h = currH;
//        }
//        return h;
//    }
//
//}
