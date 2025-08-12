class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        auto ans = vector<int> ();
        auto Set = unordered_set<int> ();
        for(auto& edge : edges) {
            Set.insert(edge[1]);
        }
        for(int i = 0; i < n; i++) {
            if(Set.find(i) == Set.end()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};