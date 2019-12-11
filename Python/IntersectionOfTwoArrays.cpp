

/**Given two arrays, write a function to compute their intersection.
Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Note:
Each element in the result must be unique.
The result can be in any order.
 * Created by eugene on 16/6/22.
 */
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s(nums1.begin(), nums1.end()), res;
        for(auto n : nums2){
            if(s.find(n) != s.end()) res.insert(n);
        }
        return vector<int>(res.begin(), res.end());
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end()), res;
        set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(res, res.begin()));
        return vector<int>(res.begin(), res.end());
    }
};
//public class Solution {
//public int[] intersection(int[] nums1, int[] nums2) {
//        HashSet<Integer> set = new HashSet<>();
//        HashSet<Integer> same = new HashSet<>();
//        for (int i: nums1) set.add(i);
//        for (int i: nums2)
//            if (set.contains(i)) same.add(i);
//        int[] res = new int[same.size()];
//        int k = 0;
//        for (int i: same) res[k++] = i;
//        return res;
//    }
//}
