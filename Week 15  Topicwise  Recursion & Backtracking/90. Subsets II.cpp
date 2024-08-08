class Solution {
public:
    void sol(vector<int>& v, int idx, vector<vector<int>> &ans, vector<int>& temp){
        
        ans.push_back(temp);
        for(int i = idx; i < v.size(); i++){
            if(i != idx && v[i] == v[i-1])  continue;
            temp.push_back(v[i]);
            sol(v, i+1, ans, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<int> temp;
        vector<vector<int> > ans;

        sol(nums, 0, ans, temp);
        return ans;
    }
};