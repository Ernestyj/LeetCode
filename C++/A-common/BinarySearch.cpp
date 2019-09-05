
public int binarySearch(int[] nums, int target) {
    if (nums == null || nums.length == 0)  return -1;
    int l = 0, r = nums.length - 1;
    while (l + 1 < r) {   // 要点1: start + 1 < end
        int m = l + (r - l) / 2;
        if (nums[m] == target) return m;    // 要点3：=, <, > 分开讨论，mid 不+1也不-1
        else if (nums[m] < target)  l = m;
        else  r = m;
    }
    if (nums[l] == target) return l;    // 要点4: 循环结束后，单独处理start和end
    if (nums[r] == target) return r;
    return -1;
}


bool isBadVersion(int version);
int firstBadVersion(int n) {
    int l = 1, r = n, m = 0;
    while (l+1<r){
        m = l+(r-l)/2;
        if(isBadVersion(m)) r = m;
        else l = m;
    }
    if(isBadVersion(l)) return l;
    if(isBadVersion(r)) return r;
    return -1;
}
int firstBadVersion(int n) {//另一种写法
    int l = 1, r = n, m = 0;
    while (l<=r){
        m = l+(r-l)/2;
        if(isBadVersion(m)) r = m-1;
        else l = m+1;
    }
    return l;
}

int firstGeq(vector<int>& nums, int target){
    int l = 0, r = nums.size()-1, m;
    while (l+1<r){
        m = l+(r-l)/2;
        if(nums[m]>=target) r = m;
        else l = m;
    }
    if(nums[l]>=target) return l;
    if(nums[r]>=target) return r;
    return nums.size();  //TODO 找不到时，返回r+1或nums.size()，这里按题目情况返回具体标记值，方便程序判断
}

/**Given a sorted array of integers, find the starting and ending position of a given target value.
 Your algorithm's runtime complexity must be in the order of O(log n).
 If the target is not found in the array, return [-1, -1].
 For example, Given [5, 7, 7, 8, 8, 10] and target value 8,
 return [3, 4].
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return vector<int>{-1, -1};
        int l = firstGeq(nums, target);
        if(l==nums.size() || nums[l]!=target)
            return vector<int>{-1, -1};
        return vector<int>{l, firstGeq(nums, target+1)-1};
    }
    int firstGeq(vector<int>& nums, int target){
        int l = 0, r = nums.size()-1, m;
        while (l+1<r){
            m = l+(r-l)/2;
            if(nums[m]>=target) r = m;
            else l = m;
        }
        if(nums[l]>=target) return l;
        if(nums[r]>=target) return r;
        return nums.size();  //TODO 找不到时，返回r+1或nums.size()
    }
};

// 考虑使用类似于二分查找法来缩短时间。由于只是需要找到任意一个峰值，那么我们在确定二分查找折半后中间那个元素后，和紧跟的那个元素比较下大小，
// 如果大于，则说明峰值在前面，如果小于则在后面。这样就可以找到一个峰值了
int findPeakElement(vector<int>& nums) {
    int len = nums.size(), l = 0, r = len-1;
    while(l+1<r){
        int m = l+(r-l)/2;
        if(nums[m]<nums[m+1]) l = m;  //峰值在后面
        else r = m; //峰值在前面
    }
    if((l-1<0 ||nums[l-1]<nums[l]) && (l+1>=len || nums[l]>nums[l+1])) return l;
    return r;   //或者l+1=r
}

//0,1,3,5,6
//0,1,2,3,4
int hIndex(vector<int>& citations) {//标准二分法，O(log n)
    int N = citations.size(), l = 0, r = N-1, m = 0;
    if(N<=0) return 0;
    while (l+1<r){
        m = l+(r-l)/2;
        if(citations[m]<N-m) l = m;   // 如果该点是有效的H指数，则最大H指数一定在右边
        else if(citations[m]==N-m) return N-m;
        else r = m;   //// 否则最大H指数在左边
    }
    if(citations[l]>=N-l) return N-l;
    if(citations[r]>=N-r) return N-r;
    return 0;
}

/**
 * Follow up for "Search in Rotated Sorted Array":
 What if duplicates are allowed?
 Would this affect the run-time complexity? How and why?
 Write a function to determine if a given target is in the array.
 * Created by DCLab on 1/2/2016.
 */
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()<=0) return false;
        int l = 0, r = nums.size()-1, m = 0;
        while (l+1<r){
            m = l+(r-l)/2;
            if(target==nums[m]) return true;
            else if(nums[m]<nums[r]){   //m~r有序
                if(nums[m]<target && target<=nums[r]) l = m;
                else r = m;
            }else if(nums[m]>nums[r]){  //l~m有序
                if(nums[l]<=target && target<nums[m]) r = m;
                else l = m;
            }else{  //nums[m] == nums[r]时
                --r;
            }
        }
        if(nums[l]==target) return true;
        if(nums[r]==target) return true;
        return false;
    }
};

/**Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 Find the minimum element.
 You may assume no duplicate exists in the array.
 * 6 7 0 1 2 3 4
 * 4 5 6 7 0 1 2
 * Created by eugene on 16/3/12.
 */
class Solution {
public:
    int findMin(vector<int>& nums) {    //记忆
        int l = 0, r = nums.size()-1;
        while(l+1<r){
            int m = l+(r-l)/2;
            if(nums[m]<nums[r]) r = m;  //m~r有序
            else l = m;   //l~m有序
        }
        return min(nums[l], nums[r]);
    }
};