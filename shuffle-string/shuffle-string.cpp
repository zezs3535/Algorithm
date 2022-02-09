struct Node{
    char c;
    int idx;
};

bool cmp(Node &a, Node &b){
    return a.idx < b.idx;
}

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans = "";
        vector<Node> node; 
        for(int i=0;i<s.size();i++){
            node.push_back({s[i],indices[i]});
        }
        sort(node.begin(),node.end(),cmp);
        for(int i=0;i<node.size();i++){
            ans += node[i].c;
        }
        return ans;
    }
};