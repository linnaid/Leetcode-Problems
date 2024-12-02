bool isAnagram(char* s, char* t) {
    int sz1 = strlen(s), sz2 = strlen(t);
    int zm[26];
    memset(zm, 0, sizeof(zm));
    if(sz1 != sz2)
    return false;
    else
    {
        for(int i = 0; i < sz1; i++)
        {
            zm[s[i]-'a'] = zm[s[i]-'a'] + 1;
        }
        for(int i = 0; i < sz1; i++)
        {
            zm[t[i]-'a'] = zm[t[i]-'a'] - 1;
            if(zm[t[i]-'a'] < 0)
            return false;
        }
        return true;
    }
}