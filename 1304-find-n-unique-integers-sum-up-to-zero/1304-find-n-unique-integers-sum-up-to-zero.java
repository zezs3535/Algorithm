class Solution {
    public int[] sumZero(int n) {
        int[] ans = new int[n];
        int idx = 0;
        if(n%2==0){
            ans[n-1] = 0;
            for(int i=1;i<=(n/2);i++){
                ans[idx++] = i;
                ans[idx++] = i * -1;
            }
        }
        else{
            for(int i=1;i<=(n/2);i++){
                ans[idx++] = i;
                ans[idx++] = i * -1;
            }
        }
        return ans;
    }
}