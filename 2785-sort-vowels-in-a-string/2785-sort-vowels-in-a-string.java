import java.util.*;

class Solution {
    
    public static class Ja{
        char c;
        int idx;
        Ja(char c, int idx){
            this.c = c;
            this.idx = idx;
        }
    }
    
    public String sortVowels(String s) {
        int n = s.length();
        ArrayList<Ja> jal = new ArrayList<>();
        ArrayList<Character> mol = new ArrayList<>();
        
        for(int i=0;i<n;i++){
            int cur = s.charAt(i)-'A';
            if(cur==0||cur==4||cur==8||cur==14||cur==20||cur==32||cur==36||cur==40||cur==46||cur==52){
                mol.add(s.charAt(i));
            }else{
                jal.add(new Ja(s.charAt(i),i));
            }
        }
        
        Collections.sort(mol);
        
        int jaIdx=0;
        int moIdx=0;
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<n;i++){
            if(jal.size() != 0 && jaIdx < jal.size() && jal.get(jaIdx).idx==i){
                sb.append(jal.get(jaIdx).c);
                jaIdx++;
            }else{
                sb.append(mol.get(moIdx));
                moIdx++;
            }
        }
        
        return sb.toString();
    }
}