class Solution {
    public:
        bool isPalindrome(int x) {
            if(x < 0 || (x % 10 == 0 && x != 0))
            {
                return false;
            }
            int a = 0;
            while(x > a)
            {
                a = a * 10 + x % 10;
                x = x / 10;
            }
            return a == x || a / 10 == x;
        }
    };