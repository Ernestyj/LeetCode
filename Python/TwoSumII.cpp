//
// Created by Eugene on 2019-03-17.
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;

/**
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 *
 * Created by DCLab on 11/2/2015.
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size()-1;
        while(l<r){
            int val = numbers[l] + numbers[r];
            if(val == target) {
                return vector<int>{l+1, r+1};
            }else if(val < target) ++l;
            else --r;
        }
        return vector<int>{0, 0};
    }
};

//public class Solution {
//public int[] twoSum(int[] numbers, int target) {
//        if(numbers==null || numbers.length<=0) return new int[2];
//        int[] res = new int[2];
//        int l = 0, r = numbers.length-1;
//        while(l<r){
//            int v = numbers[l]+numbers[r];
//            if(v==target){
//                res[0] = l+1;
//                res[1] = r+1;
//                return res;
//            }else if(v<target) l++;
//            else r--;
//        }
//        return res;
//    }
//}

//int main() {
//    vector<int> nums{2, 7, 11, 15};
//    int target = 9;
//    Solution s;
//    auto result = s.twoSum(nums, target);
//    cout << result[0] << " " << result[1];
//}
