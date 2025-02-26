char* turn(char* s, int left, int right)
{
    while(left < right)
    {
        
        char k = s[left];
        s[left] = s[right];
        s[right] = k;
        left = left+1;
        right = right-1;
    }
    return s;
}


char* reverseStr(char* s, int k) {
    int a = strlen(s);
    int b = a;
    for(int i = 0; i < a; i++)
    {
        if(b == 1)
        break;
        else if(b <= k)
        {
            s = turn(s, i, a-1);
            break;
        }
        else if((b >k) && (b < 2*k))
        {
            s = turn(s, i, i+k-1);
            break;
        }
        else
        {
            if((i+1)%(2*k) == 0)
            {
                s = turn(s, i-(2*k)+1, i-k);
                b = b-(2*k);
            }
        }
    }
    return s;
}