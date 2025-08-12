class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = m * (1 << (n - 1));
        for(int i = 1; i < n; i++) {
            int num = 0;
            for(int j = 0; j < m; j++) {
                if(grid[j][0] == 0) {
                    num += grid[j][i];
                } else {
                    num += (1 - grid[j][i]);
                }
            }
            int k = max(num, m - num);
            ans += k * (1 << (n - i - 1));
        }
        return ans;
    }
};