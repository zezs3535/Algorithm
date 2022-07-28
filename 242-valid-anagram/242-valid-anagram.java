class Solution {
    public boolean isAnagram(String s, String t) {
        int a = s.length();
        int b = t.length();
        if(a!=b) return false;
        
        int[] arr1 = new int[26];
        int[] arr2 = new int[26];
        
        for(int i=0;i<a;i++){
            arr1[s.charAt(i)-'a'] += 1;
            arr2[t.charAt(i)-'a'] += 1;
        }
        
        for(int i=0;i<26;i++){
            if(arr1[i] != arr2[i]){
                return false;}
        }
        
        return true;
    }
}