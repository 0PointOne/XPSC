class Solution {
public:
    bool isPos(vector<string>& v, int x, int y, int n){
        int i = x, j = y;
        while(i >= 0 && j >= 0){
            if(v[i--][j--] == 'Q') return false;
        }
        i = x, j = y;
        while(i >= 0){
            if(v[i--][j] == 'Q') return false;
        }
        i = x;
        while(i >= 0 && j < n){
            if(v[i--][j++] == 'Q') return false;
        }
        return true;
    }

    void sol(vector<vector<string>>& ans, vector<string>& v, int i){

        if(i == v.size()){
            ans.push_back(v);
            return;
        }
        for(int j = 0; j < v.size(); j++){
            if(isPos(v, i, j, v.size())){
                v[i][j] = 'Q';
                sol(ans, v, i+1);
                v[i][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> v(n);
        string s(n, '.');
        for(int i = 0; i < n; i++) v[i] = s;
        sol(ans, v, 0);
        return ans;
    }
};