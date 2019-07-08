
public int binarySearch(int[] nums, int target) {
    if (nums == null || nums.length == 0)  return -1;
    int l = 0, r = nums.length - 1;
    while (l + 1 < r) {   // 要点1: start + 1 < end
        int m = l + (r - l) / 2;
        if (nums[m] == target) {  // 要点3：=, <, > 分开讨论，mid 不+1也不-1
            return m;
        } else if (nums[m] < target) {
            l = m;
        } else {
            r = m;
        }
    }
    if (nums[l] == target) {    // 要点4: 循环结束后，单独处理start和end
        return l;
    }
    if (nums[r] == target) {
        return r;
    }
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
int firstBadVersion(int n) {
    int l = 1, r = n, m = 0;
    while (l<=r){
        m = l+(r-l)/2;
        if(isBadVersion(m)) r = m-1;
        else l = m+1;
    }
    return l;
}
