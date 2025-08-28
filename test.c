#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* reverseWords(char* s) {
    int a = strlen(s);
    int left = a-1, right = a-1;
    char* num = (char*)malloc(10000);
    int n = 0, b = left;
    while(left != -1)
    {
        if((s[left] != ' ' || s[left+1] == ' ') && left != 0)
        {
            left--;
            continue;
        }
        if((s[right] == ' ') && right != 0)
        {
            right--;
            continue;
        }
        if((s[left] == ' ' || left == 0))
        {
            b = left;
            if(left != 0 || (left == 0 && s[0] == ' '))
                b = b+1;
            while((b <= right) && (s[b] != ' '))
            {
                // printf("%c ",s[b+1]);
                num[n] = s[b];
                printf("%c ",num[n],right);
                b++;
                n++;
            }
            if((b != left+1) || (s[0] != ' ' && b == 1))
            num[n++] = ' ';
            right = left;
            left--;
        }
    }
    num[n-1] = '\0';
    return num;
}


int main()
{
    char s[] = " asdasd df f";
    char* ans = reverseWords(s);
    int a = strlen(ans);

    return 0;
}

