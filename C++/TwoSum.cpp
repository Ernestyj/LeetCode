//
// Created by Eugene on 2019-03-17.
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;

/**
 * Given an array of integers, find two numbers such that they add up to a specific target number.

 The function twoSum should return indices of the two numbers such that they add up to
 the target, where index1 must be less than index2.
 Please note that your returned answers (both index1 and index2) are not zero-based.
 You may assume that each input would have exactly one solution.

 Input: numbers={2, 7, 11, 15}, target=9
 Output: index1 = 0, index2 = 1
 *
 * Created by DCLab on 11/2/2015.
 */
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.count(nums[i]) == 0)
                m.insert(make_pair(target - nums[i], i));
            else
                return vector<int>{m.at(nums[i]), i};
        }
        return vector<int>{0, 0};
    }

    vector<int> twoSum1(vector<int> &nums, int target) {
        vector<int> result = {0, 0};
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    result[0] = i;
                    result[1] = j;
                    return result;
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums{2, 7, 11, 15};
    int target = 9;
    Solution s;
    auto result = s.twoSum(nums, target);
    cout << result[0] << " " << result[1];
}
