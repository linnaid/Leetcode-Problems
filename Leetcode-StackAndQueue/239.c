/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = numsSize - k + 1;
    int* ans = (int*)malloc(sizeof(int)*(*returnSize));
    int* mem = (int*)malloc(sizeof(int)*numsSize);
    int left = 0, right = 0;
    for(int i = 0; i < numsSize; i++)
    {
        while(left < right && nums[mem[right-1]] <= nums[i])
        {
            right--;
        }
        mem[right++] = i;
        if(mem[left] <= i-k)
        {
            left++;
        }
        if(i >= k-1)
        {
            ans[i-k+1] = nums[mem[left]];
        }
    }
    free(mem);
    return ans;
}