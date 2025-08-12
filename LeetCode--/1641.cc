class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> buf(5, 1);
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < 5; j++) {
                buf[j] += buf[j - 1];
            }
        }
        return accumulate(buf.begin(), buf.end(), 0);
    }
};