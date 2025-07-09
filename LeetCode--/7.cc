class Solution {
public:
    int reverse(int x) {
        if(x > -10 && x < 10)
        return x;
        std::string ans;
        int a = 1;
        while(x%10 == 0){
            x = x/10;
        }
        int i = 0;
        long long b = x;
        while(b != 0){
            if(b < 0){
                a = 0;
                b = -1*b;
            }
            ans[i++] = b%10 + '0';
            b = b/10;
        }
        long long s = 0;
        for(int j = 0; j < i; j++){
            s += (ans[j] - '0')*pow(10, (i - j - 1));
            if(s > (pow(2, 31) - 1))
            return 0;
        }
        if(a == 1)
        return s;
        else
        return -1*s;
    }
};