class Solution {
public:
    vector<int> n;
    vector<vector<int>> ans;

    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        for(int t = 0; t < (1 << size); t++) {
            n.clear();
            for(int i = 0; i < size; i++) {
                if(t & (1 << i)) {
                    n.push_back(nums[i]);
                }
            }
            ans.push_back(n);
        }    
        return ans;
    }
};