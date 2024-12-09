// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
struct hash{
    int num;
    int mem;
    UT_hash_handle hh;
};
struct hash *hashh;

struct hash* find(int num)
{
    struct hash *p;
    HASH_FIND_INT(hashh, &num, p);
    return p;
}

void insert(int num, int mem)
{
    struct hash *p;
    p = find(num);
    if(p == NULL)
    {
        p = (struct hash*)malloc(sizeof(struct hash));
        p->num = num;
        p->mem = mem;
        HASH_ADD_INT(hashh, num, p);
    }
    else
    {
        p->mem = mem;
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    hashh = NULL;
    for(int i = 0; i < numsSize; i++)
    {
        struct hash *p = find(target - nums[i]);
        if(p != NULL)
        {
            int *tar = (int*)malloc(sizeof(int) * 2);
            tar[0] = p->mem;
            tar[1] = i;
            *returnSize = 2;
            return tar;
        }
        else
        {
            insert(nums[i], i);
        }
    } 
    *returnSize = 0;
    return NULL;
}