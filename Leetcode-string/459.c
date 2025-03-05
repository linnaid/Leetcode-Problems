bool repeatedSubstringPattern(char* s) {
    int a = strlen(s);
    for(int i = 1; i <= a/2; i++)
    {
        if(a % i == 0)
        {
            bool m = true;
            for(int j = i; j < a; j++)
            {
                if(s[j] != s[j-i])
                m = false;
            }
            if(m)
            return true;
        }
    }
    return false;
}