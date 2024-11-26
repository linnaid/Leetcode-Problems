/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(n*sizeof(int));
    int** name = (int**)malloc(n*sizeof(int*));
    int left = 0, on = 0, right = n-1, down = n-1;
    int num = 1;
    for (int i = 0; i < n; i++) {
        name[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
        memset(name[i], 0, sizeof(int) * n);
    }
    while(on <= down && left <= right)
    {
        for(int i = left; i <= right; i++)
        {
            name[on][i] = num;
            num++;
        }
        on++;
        for(int i = on; i <= down; i++)
        {
            name[i][right] = num;
            num++;
        }
        right--;
        for(int i = right; i >= left; i--)
        {
            name[down][i] = num;
            num++;
        }
        down--;
        for(int i = down; i >= on; i--)
        {
            name[i][left] = num;
            num++;
        }
        left++;
    }
    // for(int i = 0; i < n; i++)
    // {
    //     printf("[");
    //     for(int j = 0; j < n; j++)
    //     {
    //         printf("%d，",name[i][j]);
    //     }
    //     printf("],");
    // }
    return name;
}
