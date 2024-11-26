int minSubArrayLen(int target, int* nums, int numsSize) {
    int left = 0, right = 0,add = 0;
    int small = 100000000;
    for(int i = 0; i < numsSize; i++)
    {
        add += nums[right];
        right++;
        while(add >= target)
        {
            small = (small < right - left + 1)?small:right - left + 1;
            add -= nums[left];
            left++;
        }
    }
    return (small == 100000000)?0:small-1;
}