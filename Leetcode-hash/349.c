/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *arr1 = (int*)malloc(1000 * sizeof(int));
    int a = 0;
    for(int i = 0; i < nums1Size; i++)
    {
        for(int j = 0; j < nums2Size; j++)
        {
            if(nums1[i] == nums2[j])
            {
                arr1[a] = nums1[i];
                a++;
                break;
            }
        }
    }
    int sz = a;
    if(a == 0)
    {
        *returnSize = 0;
        free(arr1);
        return NULL;
    }
    int *arr = (int*)malloc(sz * sizeof(int));
    for(int i = 0; i < sz; i++)
    {
        for(int j = 0; j < sz - i - 1; j++)
        {
            if(arr1[j+1] > arr1[j])
            {
                int k = arr1[j];
                arr1[j] = arr1[j+1];
                arr1[j+1] = k;
            }
        }
    }
    arr[0] = arr1[0];
    int j = 1;
    for(int i = 1; i < sz; i++)
    {
        if(arr1[i] != arr1[i-1])
        {
            arr[j] = arr1[i];
            j++;
        }
    }
    *returnSize = j;
    free(arr1);
    return arr;
}