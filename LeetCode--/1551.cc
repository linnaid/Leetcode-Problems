class Solution {
public:
    int minOperations(int n) {
        int ret = 0;
        for(int i = 0; i < n; i++){
            int x = 2 * i + 1;
            if(x > n) {
                ret += x-n;
            }
        }
        return ret;
    }
};