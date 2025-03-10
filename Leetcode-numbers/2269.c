int divisorSubstrings(int num, int k) {
    int arr[10], i = 0, b = 0;
    if(num == 0)
    return 0;
    int mem = num;
    while(mem)
    {
        arr[i++] = mem%10;
        mem = mem/10;
    }
    if(i == 1 && k == 1)
    return 1;
    for(int j = i-1; j >= 0; j--)
    {
        double n = 0;
        for(int l = 0; l < k; l++)
        {
            if(j >= k-1)
            {
                n += arr[j-l] * pow(10, k-l-1);
            }
        }
        if(n == 0)
        continue;
        if(num % (int)n == 0)
        {
            b++;
        }
    }
    return b;
}