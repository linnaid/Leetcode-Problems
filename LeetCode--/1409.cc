class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> buf(m);
        iota(buf.begin(), buf.end(), 1);
        vector<int> ans;
        for(int& it : queries) {
            int pos = -1;
            for(int i = 0; i < m; i++) {
                if(buf[i] == it) {
                    pos = i;
                    break;
                }
            }
            ans.push_back(pos);
            buf.erase(buf.begin() + pos);
            buf.insert(buf.begin(), it);
        }
        return ans;
    }
};