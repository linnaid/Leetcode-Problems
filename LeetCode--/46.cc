class Solution {
public:

    void dfs(int start, vector<int> nums) {
        
        if(_path.size() == nums.size()) {
            ans.push_back(_path);
            return;
        }

        for(int i = 0 ; i < nums.size(); i++) {
            if(!d[i]) {
                d[i] = true;
                _path.push_back(nums[i]);
                dfs(i + 1, nums);
                d[i] = false;
                _path.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        dfs(0, nums);
        return ans;
    }

    vector<int> _path;
    vector<vector<int>> ans;
    bool d[6];
};