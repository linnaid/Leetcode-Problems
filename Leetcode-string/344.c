void reverseString(char* s, int sSize) {
    int left = 0, right = sSize-1;
    while(left < right)
    {
        char k = s[left];
        s[left] = s[right];
        s[right] = k;
        left++;
        right--;
    }
}