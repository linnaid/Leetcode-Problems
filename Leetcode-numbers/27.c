int removeElement(int* nums, int numsSize, int val) {
    int n = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] == val)
        {
            nums[i] = 0;
            n++;
        }
    }
    int k = numsSize - n;
    for(int i = 0; i < numsSize; i++)
    {
        for(int j = 0; j < numsSize - i - 1; j++)
        {
            if(nums[j] < nums[j+1])
            {
                int f = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = f;
            }
        }
    }
    return k;
}