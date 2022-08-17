class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        String[] arr = new String[]{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        HashMap<String,Integer> hmap = new HashMap<>();
        for(String s : words){
            String tmp = "";
            for(int i=0;i<s.length();i++){
                tmp += arr[s.charAt(i)-'a'];
            }
            hmap.put(tmp,0);
        }
        
        return hmap.size();
    }
}