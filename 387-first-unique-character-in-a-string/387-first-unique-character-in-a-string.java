class Solution {
    public int firstUniqChar(String s) {
        //non-appear 0
        //first appear 1
        //repeating appear 2
        int[] idx = new int[26];
        int[] repeat = new int[26];
        int ans = 999999;
        for(int i=0;i<26;i++){
            repeat[i] = -1;
        }
        int cnt = 0;
        for(char c : s.toCharArray()){
            int i = c-'a';
            if(idx[i] == 0){ //non-appear
                idx[i] = 1;
                repeat[i] = cnt;
            }else if(idx[i] == 1){ //first appear
                idx[i] = 2;
                repeat[i] = -1;
            }
            cnt++;
        }
        for(int i : repeat) ans = (i==-1)?ans:Math.min(ans,i);
        return ans == 999999?-1:ans;
    }
}