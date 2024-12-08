int numm(int n)
{
    int num = 0;
    while(n)
    {
        num += (n%10) * (n%10);
        n = n/10;
    }
    return num;
}

bool isHappy(int n){
    int num[1000],a = 0;
    memset(num, 0, sizeof(num));
    while(a != 1)
    {
        a = numm(n);
        if(num[a] == 1)
        return false;
        else
        num[a]++;
        n = a;
    }
    return true;
}
