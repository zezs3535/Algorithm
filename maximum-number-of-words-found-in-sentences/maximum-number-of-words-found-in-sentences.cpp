class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;
        for(int i=0;i<sentences.size();i++){
            int cnt = 0;
            for(char c : sentences[i]){
                if(c==' ')cnt++;
            }
            ans = max(ans,cnt);
        }
        return ans+1;
    }
};