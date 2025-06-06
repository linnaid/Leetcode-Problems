class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int n = nums.size();
            int left = 0, right = n - 1, num = n;
            while(left <= right)
            {
                int mid = ((right - left) >> 1) + left;
                if(target <= nums[mid])
                {
                    num = mid;
                    right = mid - 1;
                }
                else{
                    left = mid +1;
                }
            }
            return num;
        }
    };