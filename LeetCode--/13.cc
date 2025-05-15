class Solution {
    private:
        unordered_map<char, int> s_num = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
    public:
        int romanToInt(string s) {
            int n = 0;
            int l = s.length();
            for(int i = 0; i < l; i++)
            {
                if(i < l - 1 && s_num[s[i]] < s_num[s[i+1]])
                {
                    n = n - s_num[s[i]];
                }
                else
                {
                    n = n + s_num[s[i]];
                }
            }
            return n;
        }
    };