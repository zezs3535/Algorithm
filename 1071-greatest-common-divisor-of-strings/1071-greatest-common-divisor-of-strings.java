class Solution {
    public String gcdOfStrings(String str1, String str2) {
        int g = gcd(str1.length(),str2.length());
        if(!(str1+str2).equals(str2+str1))return "";
        return str1.substring(0,g);
    }
    
    public int gcd(int p, int q){
        if(q==0)return p;
        else return gcd(q,p%q);
    }
}