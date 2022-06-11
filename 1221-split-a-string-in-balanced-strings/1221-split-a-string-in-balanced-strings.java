class Solution {
    public int balancedStringSplit(String s) {
        int ans = 0;
        int n = s.length();
        int rcnt=0;
        int lcnt=0;
        
        for(int i=0;i<n;i++){
            if(s.charAt(i) == 'R'){
                rcnt++;
                if(lcnt > 0 && lcnt == rcnt){
                    ans++;
                    lcnt=0;
                    rcnt=0;
                }
            }
            else if(s.charAt(i)=='L'){
                lcnt++;
                if(rcnt > 0 && lcnt == rcnt){
                    ans++;
                    lcnt=0;
                    rcnt=0;
                }
            }
        }
        return ans;
    }
}