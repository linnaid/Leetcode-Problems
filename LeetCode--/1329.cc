class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> buf(m + n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                buf[i - j + m].push_back(mat[i][j]);
            }
        }
        for(auto& it : buf) {
            sort(it.rbegin(), it.rend());
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                mat[i][j] = buf[i - j + m].back();
                buf[i - j + m].pop_back();
            }
        }
        return mat;
    }
};