class Solution {
    public int countMatches(List<List<String>> items, String ruleKey, String ruleValue) {
        System.out.println(items.get(0).get(0));
        int idx = -1;
        int ans = 0;
        if(ruleKey.equals("type")) idx = 0;
        else if(ruleKey.equals("color")) idx = 1;
        else if(ruleKey.equals("name")) idx = 2;
        for(int i=0;i<items.size();i++){
            if(items.get(i).get(idx).equals(ruleValue))ans++;
        }
        return ans;
    }
}