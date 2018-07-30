class Solution {
    public int searchInsert(int[] nums, int target) {
        int low = 0;
        int high = nums.length - 1;
        int mid = (low + high) / 2;
        while(low < high) {
            if(target > nums[mid]) {
                low = mid + 1;
                mid = (low + high) / 2;
            } else if(target < nums[mid]) {
                high = mid - 1;
                mid = (low + high) / 2;
            } else {
                return mid;
            }
        }
        if(target > nums[mid]) {
            return mid + 1;
        } else if(target < nums[mid]) {
            return mid;
        } else {
            return mid;
        }
    }
}
