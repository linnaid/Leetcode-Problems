/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #include<math.h>
char** commonChars(char** words, int wordsSize, int* returnSize) {
    int z[26],c[26];
    memset(z,0,sizeof(z));
    for(int i = 0; i < 26; i++)
    c[i] = INT_MAX;
    for(int i = 0; i < wordsSize; i++)
    {
        memset(z,0,sizeof(z));
        int n = strlen(words[i]);
        for(int j = 0; j < n; j++)
        {
            z[words[i][j] - 'a'] = z[words[i][j] - 'a'] + 1;
        }
        for(int j = 0; j < 26; j++)
        {
            c[j] = fmin(c[j], z[j]);
        }
    }
    int sz = strlen(words[0]);
    char **rt = (char**)malloc(sz * sizeof(char**));
    *returnSize = 0;
    for(int i = 0; i < 26; i++)
    {
        if(c[i])
        {
            for(int j = 1; j <= c[i]; j++)
            {
                rt[*returnSize] = (char*)malloc(2 * sizeof(char));
                if(rt[*returnSize] == NULL)
                exit(1);
                rt[*returnSize][0] = i + 'a';
                rt[*returnSize][1] = '\0';
                (*returnSize)++;
            }
        }
    }
    return rt;
}