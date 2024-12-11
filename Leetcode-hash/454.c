struct hash{
    int num;
    int mem;
    UT_hash_handle hh;
};

int fourSumCount(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* nums4, int nums4Size) {
    int n = 0;
    struct hash* hashh = NULL;
    for(int i = 0; i < nums1Size; i++)
    {
        for(int j = 0; j < nums2Size; j++)
        {
            int numm = nums1[i] + nums2[j];
            struct hash* number;
            HASH_FIND_INT(hashh, &numm, number);
            if(number == NULL)
            {
                number = malloc(sizeof(struct hash));
                number->num = numm;
                number->mem = 1;
                HASH_ADD_INT(hashh, num, number);
            }
            else
            number->mem++;
        }
    }
    for(int i = 0; i < nums3Size; i++)
    {
        for(int j = 0; j < nums4Size; j++)
        {
            int a = -nums3[i]-nums4[j];
            struct hash* number;
            HASH_FIND_INT(hashh, &a, number);
            if(number != NULL)
            n = n + number->mem;
        }
    }
    return n;
}