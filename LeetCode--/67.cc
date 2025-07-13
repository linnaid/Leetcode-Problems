class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int num = 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int n = max(a.size(), b.size());
        for(int i = 0; i < n; i++){
            num += i < a.size() ? (a.at(i) == '1') : 0;
            num += i < b.size() ? (b.at(i) == '1') : 0;
            ans.push_back((num % 2 == 1) ? '1' : '0');
            num /= 2;
        }
        if(num){
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};