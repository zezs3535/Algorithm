class Solution {
    public int[] findArray(int[] pref) {
        int n = pref.length;
        if(n==1)return pref;
        
        int[] ans = new int[n];
        ans[0] = pref[0];
        for(int i=1;i<n;i++)ans[i] = pref[i-1]^pref[i];
        
        return ans;
    }
}