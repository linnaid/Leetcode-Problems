class Solution {
    public:
        string intToRoman(int num) {
            int flags[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
            string ords[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
            string ass;
            for(int i = 0; i < 13; i++)
            {
                while(num >= flags[i])
                {
                    num -= flags[i];
                    ass += ords[i];
                }
            }
            return ass;
        }
    };