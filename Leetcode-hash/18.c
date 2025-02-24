/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 int cmp(const void *a, const void *b)
 {
    return *(int*)a - *(int*)b;
 }
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    int** mem = (int**)malloc(sizeof(int*) * 10000);
    *returnSize = 0;
    if(numsSize < 4)
    return mem;
    qsort(nums, numsSize, sizeof(int), cmp);
    for(int i = 0; i < numsSize - 3; i++)
    {
        if(i > 0 && nums[i] == nums[i-1])
        continue;
        if((long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target)
        break;
        else if((long)nums[i] + nums[numsSize-1] + nums[numsSize-2] + nums[numsSize-3] < target)
        continue;
        else
        {
            for(int j = i+1; j < numsSize-2; j++)
            {
                if(j > i+1 && nums[j] == nums[j-1])
                continue;
                if((long)nums[i] + nums[j] + nums[j+1] + nums[j+2] > target)
                break;
                else if((long)nums[i] + nums[j] + nums[numsSize-1] + nums[numsSize-2] < target)
                continue;
                else
                {
                    int left = j+1;
                    int right = numsSize-1;
                    while(right > left)
                    {
                        long b =(long) nums[i] + nums[j] + nums[left] + nums[right];
                        if(b > target)
                        right--;
                        else if(b < target)
                        left++;
                        else
                        {
                            int *sum = (int*)malloc(sizeof(int) * 4);
                            sum[0] = nums[i];
                            sum[1] = nums[j];
                            sum[2] = nums[left];
                            sum[3] = nums[right];
                            mem[(*returnSize)++] = sum;
                            while(right > left && nums[right] == nums[right-1])
                            right--;
                            while(right > left && nums[left] == nums[left+1])
                            left++;
                            right--;
                            left++;
                        }
                    }
                }
            }
        }
    }
    //printf("%d\n",(*returnSize));
    *returnColumnSizes = malloc(sizeof(int*) * (*returnSize));
    for(int i = 0; i < (*returnSize); i++)
    {
        (*returnColumnSizes)[i] = 4;
    }
    return mem;
}