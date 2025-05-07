// 滑动窗口

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            unordered_set<char> ff;
            int n = s.size();
            int right = -1;
            int mm = 0;
            for(int i = 0; i < n; i++)
            {
                if(i != 0)
                {
                    ff.erase(s[i - 1]);
                }
                while(right + 1 < n && !ff.count(s[right + 1]))
                {
                    ff.insert(s[right+1]);
                    right++;
                }
                mm = max(mm, right - i + 1);
            }
            return mm;
        }
    
    };