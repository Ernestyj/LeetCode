//
// Created by Eugene on 2019-07-04.
//


struct QuickSort{
    void quickSort(vector<int>& nums){
        quickSort(nums, 0, nums.size() - 1);
    }
    void quickSort(vector<int>& arr, int left, int right) {
        int l = left, r = right, pivot = arr[(left+right)/2];
        while (l<=r) {
            while (arr[l]<pivot) l++;
            while (arr[r]>pivot) r--;
            if (l<=r) {
                swap(arr[l], arr[r]);
                l++; r--;
            }
        };// 最后退出的情况应该是右指针在左指针左边一格 r+1=l
        if (left <= r) quickSort(arr, left, r);  //TODO 注意边界，也可以是left<r和l<right，但是加等号方便统一记忆
        if (l <= right) quickSort(arr, l, right);
    }
};

//快排（另一种写法）
public int[] quickSort(int[] nums){
    quickSort(nums, 0, nums.length - 1);
    return nums;
}
private void quickSort(int[] nums, int left, int right){
    if (left < right) {
        int index = partition(nums, left, right);
        quickSort(nums, left, index - 1);
        quickSort(nums, index + 1, right);
    }
}
private int partition(int nums[], int l, int r){
    int pivot = nums[l]; //枢轴记录
    while (l < r){
        while (l<r && nums[r]>=pivot) r--;
        nums[l] = nums[r];   //交换比枢轴小的记录到左端
        while (l<r && nums[l]<=pivot) l++;
        nums[r] = nums[l];   //交换比枢轴小的记录到右端
    }
    nums[l] = pivot; //扫描完成，枢轴到位
    return l;    //返回枢轴的位置
}

