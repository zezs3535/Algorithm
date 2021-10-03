class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        for(int t=0;t<2;t++){
            for(int i=0;i<nums.size();i++){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};