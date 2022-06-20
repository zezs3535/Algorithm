class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int n = nums.length;
        int[] ans = new int[n];
        int lessIdx = 0;
        int equalIdx = 0;
        
        for(int i=0;i<n;i++){
            if(nums[i] < pivot)lessIdx++;
            else if(nums[i] == pivot)equalIdx++;
        }
        
        int greaterIdx = lessIdx + equalIdx;
        equalIdx = lessIdx;
        lessIdx = 0;
        
        for(int i=0;i<n;i++){
            if(nums[i] < pivot){
                ans[lessIdx] = nums[i];
                lessIdx++;
            } else if(nums[i] == pivot){ 
                ans[equalIdx] = nums[i];
                equalIdx++;
            } else{
                ans[greaterIdx] = nums[i];
                greaterIdx++;
            }
        }
        
        return ans;
    }
}