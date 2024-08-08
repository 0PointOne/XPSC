class Solution {
public:
    bool isPalin(string& s, int l, int r){
        while(l <= r){
            if(s[l++] != s[r--]) return false;
        }return true;
    }

    void sol(int idx, string& s, vector<string>& path, vector<vector<string>>& v){
        if(idx == s.size()){
            v.push_back(path);
            return;
        }
        for(int i = idx; i < s.size(); i++){
            if(isPalin(s, idx, i)){
                path.push_back(s.substr(idx, i - idx + 1));
                sol(i+1, s, path, v);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        sol(0, s, path, ans);
        return ans;
    }
};