class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> ans(n,false);
        int maxNum = 0;
        for(int i : candies){
            maxNum = max(maxNum, i);
        }
        for(int i=0;i<n;i++){
            if(candies[i]+extraCandies>=maxNum)ans[i]=true;
        }
        return ans;
    }
};