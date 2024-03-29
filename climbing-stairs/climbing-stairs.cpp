class Solution {
public:
    int climbStairs(int n) {
        int dp[47] = {1,1};
        if(n>1){
            for(int i=2;i<=n;i++){
                dp[i] = dp[i-1] + dp[i-2];
            }
        }
        return dp[n];
    }
};