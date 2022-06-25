class Solution {
    public List<String> cellsInRange(String s) {
        char s1 = s.charAt(0);
        char s2 = s.charAt(1);
        char s3 = s.charAt(3);
        char s4 = s.charAt(4);
        List<String> ans = new ArrayList<>();
        
        for(char c = s1; c<=s3; c++){
            for(char c1 = s2; c1<=s4; c1++){
                ans.add(""+c+c1);
            }
        }
        
        return ans; 
    }
}