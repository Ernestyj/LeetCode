
/**
 * Given a non-empty array of integers, return the k most frequent elements.
Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:
Input: nums = [1], k = 1
Output: [1]
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {//最大堆，另一种办法是桶排序
        unordered_map<int, int> m;
        priority_queue<pair<int, int>> q;
        vector<int> res;
        for(auto& a: nums) ++m[a];  //统计频次
        for(auto& it: m) q.push({it.second, it.first}); //建立优先队列
        for (int i = 0; i < k; ++i) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};

