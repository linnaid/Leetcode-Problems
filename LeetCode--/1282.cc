class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> group;
        int sizes = groupSizes.size();
        for(int i = 0; i < sizes; i++) {
            group[groupSizes[i]].emplace_back(i);
        }
        vector<vector<int>> ans;
        for(auto& [size, groups] : group) {
            int n = groups.size() / size;
            for(int i = 0; i < n; i++) {
                vector<int> g;
                int start = i * size;
                for(int j = 0; j < size; j++) {
                    g.emplace_back(groups[start + j]);
                }
                ans.emplace_back(g);
            }
        }
        return ans;
    }
};