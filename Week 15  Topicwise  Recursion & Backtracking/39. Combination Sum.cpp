class Solution {
public:
    void sol(vector<int>& candidates, int target, int i, vector<vector<int> >& ans, vector<int>& t){
    
        if(i == candidates.size() && target != 0){
            if(t.size()) t.pop_back();
            return;
        }

        if(target == 0){  
            ans.push_back(t);
            if(t.size()) t.pop_back();
            return;
        }
        
        if(candidates[i] <= target){
            t.push_back(candidates[i]);
            sol(candidates, target - candidates[i], i, ans, t); 
        }
        sol(candidates, target, i+1, ans, t);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > ans;
        vector<int> t;
        sol(candidates, target, 0, ans, t);
        return ans;
    }
};