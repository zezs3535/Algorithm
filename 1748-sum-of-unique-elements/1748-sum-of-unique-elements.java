class Solution {
    public int sumOfUnique(int[] nums) {
        int[] chk = new int[101];
        int ans = 0;
        for(int i : nums)chk[i]+=1;
        for(int i=0;i<101;i++){
            if(chk[i] == 1)ans+=i;
        }
        return ans;
    }
}