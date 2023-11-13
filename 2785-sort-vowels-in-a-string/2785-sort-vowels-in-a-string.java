import java.util.*;

class Solution {
    
    public String sortVowels(String s) {
        int n = s.length();
        ArrayList<Integer> jal = new ArrayList<>();
        ArrayList<Character> mol = new ArrayList<>();
        
        for(int i=0;i<n;i++){
            int cur = s.charAt(i)-'A';
            if(cur==0||cur==4||cur==8||cur==14||cur==20||cur==32||cur==36||cur==40||cur==46||cur==52){
                mol.add(s.charAt(i));
                jal.add(i);
            }
        }
        
        Collections.sort(mol);
        
        int jaIdx=0;
        int moIdx=0;
        char[] ans = s.toCharArray();
        for(int i=0;i<jal.size();i++)ans[jal.get(i)]=mol.get(i);
            
        return new String(ans);
    }
}