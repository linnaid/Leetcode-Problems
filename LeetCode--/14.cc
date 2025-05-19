class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            if(!strs.size())
            {
                return "";
            }
            string a = strs[0];
            int n = strs.size();
            for(int i = 1; i < n; i++)
            {
                a = Connect(a, strs[i]);
                if(!a.size())
                {
                    break;
                }
            }
            return a;
        }
        string Connect(const string& dtr1, const string& dtr2)
        {
            int len = min(dtr1.size(), dtr2.size());
            int m = 0;
            while(m < len && dtr1[m] == dtr2[m])
            {
                ++m;
            }
            return dtr1.substr(0, m);
        }
    };