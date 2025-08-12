class Solution {
public:
    void dfs(int a, int b){
        if(b == 0){
            ans.push_back(nums);
            return;
        }
        if(a == f.size() || b < f[a].first){
            return;
        }
        dfs(a + 1, b);
        int move = min(b / f[a].first, f[a].second);
        for(int i = 1; i <= move; i++){
            nums.push_back(f[a].first);
            dfs(a + 1, b - i * f[a].first);
        }
        for(int i = 1; i <= move; i++){
            nums.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for(int n:candidates){
            if(f.empty() || n != f.back().first){
                f.emplace_back(n, 1);
            }
            else{
                f.back().second++;
            }
        }
        dfs(0, target);
        return ans;
    }
private:
    vector<pair<int,int>> f;
    vector<vector<int>> ans;
    vector<int> nums;
};