class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        
        int cnt1 = 0;
        int cnt2 = 0;
        int candidate1 = 0;
        int candidate2 = 1;
        
        for(int i : nums){
            if(i == candidate1){
                cnt1++;
            }else if(i == candidate2){
                cnt2++;
            }else if(cnt1 == 0){
                candidate1 = i;
                cnt1 = 1;
            }else if(cnt2 == 0){
                candidate2 = i;
                cnt2 = 1;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        
        cnt1 = 0;
        cnt2 = 0;
        for(int i : nums){
            if(i == candidate1)cnt1++;
            if(i == candidate2)cnt2++;
        }
        if(cnt1 > nums.length/3)ans.add(candidate1);
        if(cnt2 > nums.length/3)ans.add(candidate2);
        
        return ans;
        
    }
}