class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length;
        int[] ans = new int[n+1];
        digits[n-1] += 1;
        for(int i=n-1;i>0;i--){
            if(digits[i] > 9){
                digits[i-1] += 1;
                digits[i] = 0;
            }
        }
        if(digits[0] == 10){
            ans[0] = 1;
            ans[1] = 0;
            for(int i=2;i<n;i++){
                ans[i] = digits[i];
            }
            return ans;
        }
        return digits;
    }
}