class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n = points.size(), m = queries.size();
        vector<int> ans(m);
        for(int i = 0; i < m; i++) {
            int ax = queries[i][0], ay = queries[i][1], az = queries[i][2];
            for(int j = 0; j < n; j++) {
                int px = points[j][0], py = points[j][1];
                if((ax - px) * (ax - px) + (ay - py) * (ay - py) <= az * az) {
                    ans[i]++;
                }
            }
        }
        return ans;
    }
};