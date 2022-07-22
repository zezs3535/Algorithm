class Solution {
    public char findTheDifference(String s, String t) {
        int[] sarr = new int[26];
        int[] tarr = new int[26];
        int tmp = 0;
        for(int i=0;i<s.length();i++){
            sarr[s.charAt(i)-97] +=1;
            tarr[t.charAt(i)-97] +=1;
        }
        if(s.length() > t.length())sarr[s.charAt(s.length()-1)-97] += 1;
        else{
            tarr[t.charAt(t.length()-1)-97] += 1;
        }
        //System.out.println(Arrays.toString(sarr));
        for(int i=0;i<26;i++){
            if(sarr[i] != tarr[i]){
                tmp = i;
                break;
            }
        }
        return (char)(tmp + 97);
    }
}