class Solution {
    public boolean canJump(int[] nums) {
        boolean flag = false;
        int n = nums.length;
        if(n==1)return true;
        int cnt = 1;
        for(int i = n-2; i >= 0 ; i--){
            if(nums[i]>=cnt){
                cnt = 1;
                flag = true;
            }else{
                flag = false;
                cnt++;
            }
        }
        return flag;
    }
}