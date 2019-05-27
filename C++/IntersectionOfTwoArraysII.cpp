
/**Given two arrays, write a function to compute their intersection.
 Example: Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
 Note: Each element in the result should appear as many times as it shows in both arrays.
 The result can be in any order.
 Follow up: What if the given array is already sorted? How would you optimize your algorithm?
 What if nums1's size is small compared to nums2's size? Which algorithm is better?
 What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements
 into the memory at once?
 * Created by eugene on 16/6/22.
 */
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        vector<int> res;
        for(auto n : nums1) ++map[n];
        for(auto n : nums2){
            if(map[n]-- > 0) res.push_back(n);
        }
        return res;
    }
};
//public class IntersectionOfTwoArraysII {
//
//    public int[] intersect(int[] nums1, int[] nums2) {
//        HashMap<Integer, Integer> map = new HashMap<>();
//        ArrayList<Integer> list = new ArrayList<>();
//        for (int i: nums1) map.put(i, map.containsKey(i)? map.get(i)+1 : 1);
//        for (int i: nums2) {
//            if (map.containsKey(i)){
//                if (map.put(i, map.get(i)-1)==1) map.remove(i);
//                list.add(i);
//            }
//        }
//        int[] res = new int[list.size()];
//        for (int i=0; i<list.size(); i++) res[i] = list.get(i);
//        return res;
//    }
//
//}
