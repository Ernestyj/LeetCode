
/**
 * Given a collection of intervals, merge all overlapping intervals.
 For example,
 Given [1,3],[2,6],[8,10],[15,18],
 return [1,6],[8,10],[15,18].
 注意：输入集合不一定是按区间首部排序的。
 * Created by DCLab on 12/9/2015.
 */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.size()==0) return res;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){ return a[0]<b[0];});
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if(res.back()[1] < intervals[i][0]){   // Disjoint intervals
                res.push_back(intervals[i]);
            }else{  // Overlapping intervals
                res.back()[1] = max(intervals[i][1], res.back()[1]);
            }
        }
        return res;
    }
};
//public class MergeIntervals {
//
//    public static class Interval {
//        int start;
//        int end;
//        Interval() { start = 0; end = 0; }
//        Interval(int s, int e) { start = s; end = e; }
//    }
//
//    //简洁
//    public List<Interval> merge(List<Interval> intervals) {
//        if (intervals.size() <= 1) return intervals;
//        Collections.sort(intervals, new Comparator<Interval>() {
//            @Override
//            public int compare(Interval i1, Interval i2) {
//                return Integer.compare(i1.start, i2.start);
//            }
//        });
//        List<Interval> result = new LinkedList<>();
//        int preL = intervals.get(0).start;
//        int preR = intervals.get(0).end;
//        for (Interval span : intervals) {
//            if (span.start <= preR) // Overlapping intervals, move the preR if needed
//                preR = Math.max(preR, span.end);
//            else {                     // Disjoint intervals, add the previous one and reset bounds
//                result.add(new Interval(preL, preR));
//                preL = span.start;
//                preR = span.end;
//            }
//        }
//        result.add(new Interval(preL, preR));   // Add the last interval
//        return result;
//    }
//
//    //麻烦,但速度稍快一点
//    public List<Interval> merge1(List<Interval> intervals) {
//        List<Interval> result = new ArrayList<>();
//        if (intervals == null || intervals.size() == 0) return result;
//        HashMap<Integer, Interval> map = new HashMap<>();
//        for (Interval interval : intervals){
//            if (!map.containsKey(interval.start)) map.put(interval.start, interval);
//            else {
//                Interval oldInterval = map.get(interval.start);
//                if (oldInterval.end < interval.end){
//                    map.replace(oldInterval.start, interval);
//                }
//            }
//        }
//        List<Integer> sortedIntegers = new ArrayList<Integer>(map.keySet());
//        Collections.sort(sortedIntegers);
//
//        Interval firstInterval = map.get(sortedIntegers.get(0));
//        int start = firstInterval.start;
//        int end = firstInterval.end;
//        for (Integer i : sortedIntegers){
//            Interval interval = map.get(i);
//            if (interval.start > end){
//                result.add(new Interval(start, end));
//                start = interval.start;
//                end = interval.end;
//            } else {
//                if (interval.end > end){
//                    end = interval.end;
//                }
//            }
//        }
//        result.add(new Interval(start, end));
//        return result;
//    }
//
//}
