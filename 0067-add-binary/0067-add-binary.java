class Solution {
    
    
    public String addBinary(String a, String b) {
        StringBuilder ans = new StringBuilder();
        
        int aLen = a.length()-1;
        int bLen = b.length()-1;
        
        int carry=0;
        while(aLen>=0 || bLen>=0){
            int sum = carry;
            if(aLen>=0)sum += a.charAt(aLen--) - '0';
            if(bLen>=0)sum += b.charAt(bLen--) - '0';
            
            carry = sum > 1 ? 1 : 0;
            
            ans.append(sum%2);
        }
        
        if(carry!=0) ans.append(carry);
        return ans.reverse().toString();
    }
}