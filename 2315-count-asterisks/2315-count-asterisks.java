class Solution {
    public int countAsterisks(String s) {
        int ans=0;
        int flag = 1;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='|'){
                flag^=1;
                continue;
            }
            if(s.charAt(i)=='*' && flag == 1)ans++;
        }
        return ans;
    }
}