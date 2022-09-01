class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int n = nums.length;
        int sum = 0;
        int ans = 100000;
        for(int i=0;i<n-2;i++){
            int start = i+1;
            int end = n-1;
            while(start<end){
                sum = nums[i] + nums[start] + nums[end];
                if(sum < target){
                    start++;
                }else if(sum > target){
                    end--;
                }else{
                    return sum;
                }
                if(Math.abs(sum-target)<Math.abs(ans-target)){
                    ans = sum;
                }
            }
        }
        return ans;
    }
}