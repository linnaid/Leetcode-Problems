#include<stdio.h>

int main()
{
    int Array[100000], n, a, b, add1 = 0, add2 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &Array[i]);
    }
    while (1)
    {
        scanf("%d %d", &a, &b);
        if ((a > b) || (a < 0) || (b >= n))
        {
            break;
        }
        for (; a <= b; a++, b--)
        {
            add1 += Array[a];
            add2 += Array[b];
            if (a == b)
                add1 -= Array[a];
        }
        printf("%d\n", add1 + add2);
        add1 = 0;
        add2 = 0;
    }
    
    return 0;
}