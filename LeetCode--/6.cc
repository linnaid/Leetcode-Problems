class Solution {
    public:
        string convert(string s, int numRows) {
            if(numRows < 2)
            return s;
            std::vector<string> rows(numRows);
            int flag = -1, i = 0;
            for(char c: s)
            {
                rows[i].push_back(c);
                if(i == 0 || i == numRows - 1)
                flag = -flag;
                i += flag;
            }
            std::string res;
            for(std::string l: rows)
            {
                res += l;
            }
            return res;
        }
    };