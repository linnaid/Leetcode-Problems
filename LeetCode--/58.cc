class Solution {
    public:
        int lengthOfLastWord(string s) {
            int num = s.size() - 1;
            while(s[num] == ' ')
            num--;
            int n = 0;
            while(s[num] != ' ')
            {
                n++;
                if(num == 0)
                break;
                num--;
            }
            return n;
        }
    };