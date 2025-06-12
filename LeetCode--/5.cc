class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n < 2)
        return s;
        vector<vector<int>> nums(n, vector<int>(n));
        for(int i = 0; i < n; i++)
        nums[i][i] = true;
        int begin = 0;
        int maxlen = 1;
        for(int L = 2; L <= n; L++){
            for(int i = 0; i < n; i++){
                int j = L + i - 1;
                if(j >= n)
                break;
                if(s[i] != s[j])
                nums[i][j] = false;
                else{
                    if(j - i < 3)
                    nums[i][j] = true;
                    else
                    nums[i][j] = nums[i + 1][j - 1];
                }

                if(nums[i][j] && j - i + 1 > maxlen)
                {
                    maxlen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxlen);
    }
};