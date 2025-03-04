int strStr(char* haystack, char* needle) {
    int a = strlen(haystack);
    int n = 0;
    int b = strlen(needle);
    int c = 0;
    for(int i = 0; i < a; i++)
    {
        if(haystack[i] == needle[0])
        {
            for(int j = 0; j < b; j++)
            {
                if(haystack[i+j] != needle[j])
                break;
                else
                c++;
            }
            if(c == b)
            return i;
            else
            c = 0;
        }
        continue;
    }
    return -1;
}