class Solution {
    public int searchInsert(int[] nums, int target) {
        int ans = 0;
        int l=0;
        int r=nums.length-1;
        int mid = 0;
        int cnt=0;
        while(l<=r){
            mid = (l+r)/2;
            int cur = nums[mid];
            
            if(cur == target){
                return mid;
            }else if(cur<target){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return l;
    }
}