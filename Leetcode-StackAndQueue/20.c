char turn(char a)
{
    if(a == ')')
    return '(';
    else if(a == ']')
    return '[';
    else if(a == '}')
    return '{';
    else
    return 0;
}

bool isValid(char* s) {
    int sum = strlen(s);
    if(sum % 2 == 1)
    return false;
    int b = 0;
    int ans[10000];
    for(int i = 0; i < sum; i++)
    {
        char a = turn(s[i]);
        if(a)
        {
            if(b == 0 || ans[b-1] != a)
            {
                return false;
            }
            b--;
        }
        else
        {
            ans[b++] = s[i];
        }
    }
    if(b != 0)
    return false;
    return true;
}