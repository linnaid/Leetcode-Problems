
int removeDuplicates(int* nums, int numsSize) {
    int left = 0, right = 0;
    int n = 0;
    if(numsSize == 1)
    return 1;
    while(right < numsSize-1)
    {
        if(nums[right] != nums[right+1])
        {
            n = right;
            nums[left++] = nums[right++];
            printf("%d ",nums[left-1]);
        }
        else
        right++;
    }
    if((nums[n] != nums[right]) || (nums[right] != nums[right-1]))
    nums[left] = nums[right];
    return left+1;
}