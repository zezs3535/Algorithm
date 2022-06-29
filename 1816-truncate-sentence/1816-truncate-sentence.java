class Solution {
    public String truncateSentence(String s, int k) {
        String ans = "";
        int cnt = 0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i) == ' '){
                cnt++;
                if(cnt==k)break;
                ans += s.charAt(i);
            }
            else{
                ans += s.charAt(i);
            }
        }
        return ans;
    }
}