char* reverseWords(char* s) {
    int a = strlen(s);
    char num[1000][10000];
    char* ans = malloc(10000);
    int l = 0;
    int n = 0, m = 0;
    for(int i = 0; i < a; i++)
    {
        m = 0;
        if(s[i] != ' ')
        {
            num[n][m++] = s[i];
            printf("%c%d ",num[n][m-1],n);
            if(s[i+1] = ' ')
            n++;
            continue;
        }
        else
        {
            continue;
        }
        
    }
    printf("%c ",num[0][1]);
    for(int i = 0; i < n; i++)
    {
        int j = strlen(num[i]);
        printf("%d ",j);
        for(int k = 0; k < j; k++)
        {
            ans[l++] = num[i][k];
        }
        ans[l++] = ' ';
    }
    ans[l] = '\0';
    return ans;
}