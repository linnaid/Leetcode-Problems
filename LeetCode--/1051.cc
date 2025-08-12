class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> nums(heights);
        sort(nums.begin(), nums.end());
        int size = heights.size();
        int ans = 0;
        for(int i = 0; i < size; i++) {
            if(heights[i] != nums[i]) {
                ans++;
            }
        }
        return ans;
    }
};