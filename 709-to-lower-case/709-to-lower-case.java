class Solution {
    public String toLowerCase(String s) {
        String ans = "";
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)<= 'Z' && s.charAt(i) >= 'A'){
                ans += (char)(s.charAt(i)+32);
            }
            else{
                ans+=s.charAt(i);
            }
        }
        return ans;
    }
}