class Solution {
    public boolean checkIfPangram(String sentence) {
        boolean[] chk = new boolean[26];
        for(int i=0;i<sentence.length();i++){
            chk[sentence.charAt(i)-'0'-49]=true;
        }
        boolean ans = true;
        for(int i=0;i<26;i++){
            if(chk[i]==false){
                ans=false;
                break;
            }
        }
        return ans;
    }
}