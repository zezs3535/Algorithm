class Solution {
    public int lengthOfLIS(int[] nums) {
        int ans = 0;
        int n = nums.length;
        int[] dp = new int[n];
        for(int i=0;i<n;i++)dp[i]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i] = Math.max(dp[i],dp[j]+1);
                }
            }
        }
        for(int i=0;i<n;i++)ans = Math.max(ans,dp[i]);
        return ans;
    }
}