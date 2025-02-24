/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 int cmp(const void*a, const void*b)
 {
    return *(int*)a - *(int*)b;
 }
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int** mem = (int**)malloc(sizeof(int*) * 1000000);
    *returnSize = 0;
    if(numsSize < 3)
    {
        *returnSize = 0;
        return mem;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    for(int i = 0; i < numsSize - 2; i++)
    {
        if(nums[i] > 0)
        {
            break;
        }
        if(i > 0 && nums[i-1] == nums[i])
        continue;
        int left = i + 1;
        int right = numsSize - 1;
        while(right > left)
        {
            int b = nums[i] + nums[left] + nums[right];
            
            if(b > 0)
            right--;
            else if(b < 0)
            left++;
            else
            {
                int* sum = malloc(sizeof(int) * 3);
                sum[0] = nums[i];
                sum[1] = nums[left];
                sum[2] = nums[right];
                mem[(*returnSize)++] = sum;
                //printf("%d %d %d\n",sum[0],sum[1],sum[2]);
                while(right > left && nums[right] == nums[right-1])
                right--;
                while(right > left && nums[left] == nums[left+1])
                left++;
                right--;
                left++;
            }
        }
    }
    //printf("%d\n",(*returnSize));
    *returnColumnSizes = malloc(sizeof(int*) * (*returnSize));
    //printf("%d\n",(*returnSize));
    for(int i = 0; i < *returnSize; i++)
    {
        (*returnColumnSizes)[i] = 3;
        //printf("%d\n",i);

    }
    return mem;
}