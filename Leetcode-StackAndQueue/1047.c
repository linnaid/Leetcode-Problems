
char* removeDuplicates(char* s) {
    int a = strlen(s);
    int num = -1;
    char* add = (char*)malloc(a+1);
    for(int i = 0; i < a; i++)
    {
        if(num != -1 && s[i] == add[num])
        num--;
        else
        {
            add[++num] = s[i];
        }
    }
    add[num+1] = '\0';
    return add;
}