bool canConstruct(char* ransomNote, char* magazine) {
    int arr[26];
    memset(arr, 0, sizeof(arr));
    int sz1 = strlen(ransomNote);
    int sz2 = strlen(magazine);
    for(int i = 0; i < sz1; i++)
    {
        arr[ransomNote[i] - 'a']++;
    }
    for(int i = 0; i < sz2; i++)
    {
        arr[magazine[i] - 'a']--;
    }
    for(int i = 0; i < 26; i++)
    {
        if(arr[i] > 0)
        return false;
    }
    return true;
}