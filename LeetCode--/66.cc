class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size() - 1; i >= 0; i--){
            if(digits[i] != 9){
                ++digits[i];
                for(int j = i + 1; j < digits.size(); j++){
                    digits[j] = 0;
                }
                return digits;
            }
        }
        vector<int> ans(digits.size() + 1);
        ans[0] = 1;
        return ans;
    }
};