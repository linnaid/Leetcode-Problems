class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0, d = 0;
        for(auto c : s) {
            c == 'L' ? d++ : d--;
            if(d == 0)
            ans++;
        }
        return ans;
    }
};