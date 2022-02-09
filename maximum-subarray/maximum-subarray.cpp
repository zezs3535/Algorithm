class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int low = -2147483647;
        int sum=0;
        int ans=low;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(ans<sum)ans=sum;
            if(sum < 0){
                sum = 0;
            }
        }
        return ans;
    }
};