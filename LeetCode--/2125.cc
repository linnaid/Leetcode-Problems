class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int start = 0, ans = 0;
        int size = bank.size();
        for(auto& it : bank) {
            int buf = count_if(it.begin(), it.end(), [](char c) {return c == '1';});
            if(buf > 0) {
                ans += start * buf;
                start = buf;
            }
        }
        return ans;
    }
};