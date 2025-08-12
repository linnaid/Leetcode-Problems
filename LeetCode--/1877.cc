class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int size = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < size / 2; i++) {
            ans = max(ans, (nums[i] + nums[size - 1 - i]));
        }
        return ans;
    }
};