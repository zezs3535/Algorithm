class Solution {
    public List<String> wordSubsets(String[] words1, String[] words2) {
        int[] cnt = new int[26];
        for(String s : words2){
            int[] tmpcnt = new int[26];
            for(char c : s.toCharArray()){
                tmpcnt[c-'a'] += 1;
            }
            for(int i=0;i<26;i++){
                cnt[i] = Math.max(cnt[i], tmpcnt[i]);
            }
        }
        
        List<String> ans = new ArrayList<>();
        
        for(String s : words1){
            int[] tmpcnt = new int[26];
            boolean flag = true;
            for(char c : s.toCharArray()){
                tmpcnt[c-'a'] += 1;
            }
            for(int i=0;i<26;i++){
                if(cnt[i] > tmpcnt[i]){
                    flag = false;
                    break;
                }
            }
            if(flag)ans.add(s);
        }
        
        return ans;
    }
}