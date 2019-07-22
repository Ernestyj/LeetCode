
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
